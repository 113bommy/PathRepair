#include <bits/stdc++.h>
using namespace std;
int n, v[100000], c[100000];
int q, a, b;
long long f[100000 + 1];
bool m[100000 + 1];
int x, y;
long long query(long long a, long long b) {
  memset(f, 0, sizeof(f));
  memset(m, 0, sizeof(m));
  f[0] = x = y = 0;
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    long long other = c[i] == x ? f[y] : f[x];
    if (m[c[i]]) {
      long long old = f[c[i]];
      f[c[i]] = max(old, max(old + v[i] * a, other + v[i] * b));
    } else {
      f[c[i]] = other + v[i] * b;
      m[c[i]] = 1;
    }
    res = max(res, f[c[i]]);
    if (c[i] == x || c[i] == y) {
      if (f[x] < f[y]) {
        int tmp = x;
        x = y;
        y = x;
      }
    } else {
      if (f[c[i]] > f[x]) {
        y = x;
        x = c[i];
      } else if (f[c[i]] > f[y]) {
        y = c[i];
      }
    }
  }
  return res;
}
int main(int argc, char *argv[]) {
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < q; ++i) {
    cin >> a >> b;
    cout << query(a, b) << endl;
  }
  return 0;
}
