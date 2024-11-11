#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 100;
const int mod = 1e9 + 7;
long long int d[maxn], a[maxn], c[maxn];
long long int p(int x, int y) {
  if (x == 0) return 0;
  if (y == 0) return 1;
  long long int d = p(x, y / 2);
  if (y % 2 == 0) return ((d * d) % mod);
  d = d * d;
  d = d % mod;
  return ((d * x) % mod);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  c[0] = 1;
  for (int i = 1; i <= n; i++)
    c[i] = (c[i - 1] * (k + i - 1)) % mod * p(i, mod - 2) % mod;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++) d[i] = (d[i] + a[j] * c[i - j]) % mod;
  for (int i = 1; i <= n; i++) cout << a[i] << " ";
  cout << endl;
}
