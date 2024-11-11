#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const double eps = 1e-8;
const int nm = 300005;
int n, k, m, t;
long long res;
int a[nm];
char s[nm];
bool check[nm];
long long Pow(int x, int mu) {
  if (mu == 0) return 1ll;
  long long res = Pow(x, mu >> 1);
  res = res * res % MOD;
  if (mu & 1) res = res * x % MOD;
  return res;
}
int main() {
  int i, j, x, y, z, w;
  scanf("%d%d", &n, &m);
  if (m == 3) {
    if (n == 3) {
      cout << "0 0\n1 1\n0 1";
    } else if (n == 4) {
      cout << "0 0\n0 5\n5 0\n1 1";
    } else
      cout << "-1";
  } else {
    for (i = 1; i <= m; i++) {
      cout << i << " " << i * i << "\n";
    }
    for (i = 1; i <= n - m; i++) {
      cout << i << " " << -i * i << "\n";
    }
  }
  return 0;
}
