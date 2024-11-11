#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
const int EPS = 1e-9;
const int N = (2e5 + 20);
using namespace std;
int t[2 * N], d[2 * N], h;
int n;
bool used[N];
vector<int> xd1;
vector<int> xd2;
void apply(int p, int value) {
  t[p] += value;
  if (p < n) d[p] += value;
}
void push(int p) {
  for (int s = h; s > 0; s--) {
    int i = p >> s;
    if (d[i] != 0) {
      apply(i << 1, d[i]);
      apply(i << 1 | 1, d[i]);
      d[i] = 0;
    }
  }
}
void build(int p) {
  while (p > 1) p >>= 1, t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
}
void modify(int a, int b, int val) {
  a += n, b += n;
  int a0 = a, b0 = b;
  while (a <= b) {
    if (a % 2 == 1) apply(a++, val);
    if (b % 2 == 0) apply(b--, val);
    a /= 2, b /= 2;
  }
  build(a0);
  build(b0);
}
int query(int a, int b) {
  a += n, b += n;
  int ans = -1e7;
  push(a);
  push(b);
  while (a <= b) {
    if (a % 2 == 1) ans = max(ans, t[a++]);
    if (b % 2 == 0) ans = max(ans, t[b--]);
    a /= 2, b /= 2;
  }
  return ans;
}
int go(int a) {
  int l = 0;
  int r = n - 1;
  int mid;
  while (1) {
    mid = (l + r) / 2;
    if (l == r - 1) {
      if (!used[l] and l - query(l, l) == a and
          l - 1 - query(l - 1, l - 1) != a)
        return l;
      else
        return r;
    }
    if (l > r) break;
    if (!used[mid] and mid - query(mid, mid) == a and
        mid - 1 - query(mid - 1, mid - 1) != a)
      break;
    if (mid - query(mid, mid) >= a)
      r = mid - 1;
    else
      l = mid;
  }
  return mid;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  h = sizeof(int) * 8 - __builtin_clz(n);
  for (int i = 0; i < n; i++) t[i + n] = i;
  for (int i = n - 1; i >= 1; i--) t[i] = max(t[i << 1], t[i << 1 | 1]);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    xd1.push_back(query(a, a));
    modify(a, n - 1, -1);
  }
  for (int i = 0; i < 2 * N; i++) t[i] = 0, d[i] = 0;
  h = sizeof(int) * 8 - __builtin_clz(n);
  for (int i = 0; i < n; i++) t[i + n] = i;
  for (int i = n - 1; i >= 1; i--) t[i] = max(t[i << 1], t[i << 1 | 1]);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    xd2.push_back(query(a, a));
    modify(a, n - 1, -1);
  }
  vector<int> suma;
  suma.resize(n + 1);
  int aea = 0;
  for (int i = n - 2; i >= 0; i--) {
    int w = xd1[i] + xd2[i];
    int r = w % (n - i);
    int d = w / (n - i);
    aea += r;
    if (i != 0) {
      suma[i] = r;
      xd1[i - 1] += d;
    } else
      suma[i] = r;
  }
  for (int i = 0; i < 2 * N; i++) t[i] = 0, d[i] = 0;
  h = sizeof(int) * 8 - __builtin_clz(n);
  for (int i = 0; i < n; i++) t[i + n] = 0;
  for (int i = n - 1; i >= 1; i--) t[i] = max(t[i << 1], t[i << 1 | 1]);
  vector<int> resp;
  for (int i = 0; i < n - 1; i++) {
    int a = suma[i];
    int we = go(a);
    resp.push_back(we);
    used[we] = true;
    modify(we, n - 1, +1);
  }
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      resp.push_back(i);
      break;
    }
  }
  for (int i = 0; i < n; i++) cout << resp[i] << " ";
  cout << endl;
  return 0;
}
