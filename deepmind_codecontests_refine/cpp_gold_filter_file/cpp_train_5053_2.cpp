#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.141592653589793238462643383279502884L;
const long double E = 2.718281828459045235360287471352662498L;
const long double EPS = 1e-12L;
int n, k, t, v;
int c[524288];
bool ok1(int p) {
  int r = 0;
  for (int i = 0; i < n && r <= k; ++i) r += max(0, p - c[i]);
  return r <= k;
}
bool ok2(int p) {
  int r = 0;
  for (int i = 0; i < n && r <= k; ++i) r += max(0, c[i] - p);
  return r <= k;
}
int l_b() {
  int l = 1;
  int r = 2000000001;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (ok1(m)) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}
int r_b() {
  int l = 0;
  int r = 2000000000;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (ok2(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  return r;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(12);
  cout.setf(ios::fixed);
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &c[i]);
  }
  t = k;
  v = l_b();
  for (int i = 0; i < n; ++i) {
    t -= max(0, v - c[i]);
    c[i] = max(c[i], v);
  }
  for (int i = 0; i < n && t > 0; ++i) {
    if (c[i] == v) {
      c[i]++;
      t--;
    }
  }
  t = k;
  v = r_b();
  for (int i = 0; i < n; ++i) {
    t -= max(0, c[i] - v);
    c[i] = min(c[i], v);
  }
  for (int i = 0; i < n && t > 0; ++i) {
    if (c[i] == v) {
      c[i]--;
      t--;
    }
  }
  t = 0;
  v = 2000000001;
  for (int i = 0; i < n; ++i) {
    t = max(c[i], t);
    v = min(c[i], v);
  }
  cout << t - v << endl;
  return 0;
}
