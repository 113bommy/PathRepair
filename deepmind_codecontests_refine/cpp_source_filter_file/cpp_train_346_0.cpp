#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
const double PI = acos(-1);
const double EPS = 1e-8;
long long bit[7][10][100010];
int n;
long long sum(int z, int k, int i) {
  long long s = 0;
  while (i > 0) {
    s += bit[z][k][i];
    i -= i & -i;
  }
  return s;
}
long long sum2(int z, int k, int a, int b) {
  return sum(z, k, b) - sum(z, k, a - 1);
}
void add(int z, int k, int i, int x) {
  while (i <= n) {
    bit[z][k][i] += x;
    i += i & -i;
  }
}
int f(int i, int z) {
  int p = i % (2 * (z - 1));
  if (p == 0) return 2;
  if (p <= z) return p;
  return 2 * z - p;
}
int g(int i, int z) {
  int zz = 2 * (z - 1);
  return (i % zz + zz) % zz;
}
long long a[100001];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int z = 2; z <= 6; ++z) {
      for (int t = 0; t < 2 * (z - 1); ++t) {
        add(z, t, i, a[i] * f(g(i - t, z), z));
      }
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < (int)m; ++i) {
    int t;
    cin >> t;
    if (t == 1) {
      long long p, v;
      cin >> p >> v;
      for (int z = 2; z <= 6; ++z) {
        for (int t = 0; t < 2 * (z - 1); ++t) {
          add(z, t, p, -a[p] * f(g(p - t, z), z));
          add(z, t, p, v * f(g(p - t, z), z));
        }
      }
      a[p] = v;
    } else {
      int l, r, z;
      cin >> l >> r >> z;
      int t = (l - 1) % (2 * (z - 1));
      cout << sum2(z, t, l, r) << endl;
    }
  }
}
