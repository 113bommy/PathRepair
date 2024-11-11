#include <bits/stdc++.h>
using namespace std;
using namespace std;
int n, m;
int t[4 * 100000];
void build(int a[], int v, int tl, int tr) {
  if (tl == tr)
    t[v] = a[tl];
  else {
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
  }
}
void update(int v, int tl, int tr, int l, int r, int add) {
  if (l > r) return;
  if (l == tl && tr == r)
    t[v] += add;
  else {
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), add);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
  }
}
int get(int v, int tl, int tr, int pos) {
  if (tl == tr) return t[v];
  int tm = (tl + tr) / 2;
  if (pos <= tm)
    return t[v] + get(v * 2, tl, tm, pos);
  else
    return t[v] + get(v * 2 + 1, tm + 1, tr, pos);
}
int main() {
  int x;
  cin >> x;
  vector<bool> prime(x + 1, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i <= x; ++i)
    if (prime[i])
      if (i * 1ll * i <= x)
        for (int j = i * i; j <= x; j += i) prime[j] = false;
  int i = x / 2 + 1;
  while (!(prime[i] && x % i == 0) and i > 1) {
    --i;
  }
  if (i == 1) {
    cout << x;
    return 0;
  }
  int ans = 100000000;
  for (int j = 2; j < x - i; ++j) {
    if (prime[j]) {
      int c = (x - i + 1) / j;
      if ((x - i + 1) % j != 0) {
        ++c;
      }
      int m = c * j;
      if (m <= x) {
        ans = min(ans, m - j + 1);
      }
    }
  }
  cout << ans;
  return 0;
}
