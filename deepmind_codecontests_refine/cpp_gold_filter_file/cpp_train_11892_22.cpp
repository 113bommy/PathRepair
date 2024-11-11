#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1000 + 100;
const long long mod = 1000000007;
int n, m, k;
long long d[maxn][maxn];
long long c(int a, int b) {
  if (a == 1) return 1;
  if (d[a][b] != -1) return d[a][b];
  long long res = 0;
  for (int l = 1; l <= b - 2; l++)
    res = (res + c(a - 2, l) * (b - l - 1)) % mod;
  return d[a][b] = res;
}
int main() {
  cin >> n >> m >> k;
  k++;
  if (n > m) swap(n, m);
  if (k * 2 - 1 > n) {
    cout << 0 << endl;
    return 0;
  }
  memset(d, -1, sizeof d);
  long long a = c(2 * k - 1, m);
  long long b = c(2 * k - 1, n);
  cout << (a * b) % mod << endl;
  return 0;
}
