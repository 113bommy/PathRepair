#include <bits/stdc++.h>
using namespace std;
int n;
const int INF = 1 << 28;
const double EPS = 1e-8;
const int MOD = 1000000007;
long long int C[15010][510];
long long int comb(int n, int k) {
  if (k < 0 || k > n) return 0;
  if (n == 0) return 1;
  if (C[n][k] > 0) return C[n][k];
  C[n][k] = (comb(n - 1, k - 1) + comb(n - 1, k)) % MOD;
  return C[n][k];
}
int main() {
  scanf("%d", &n);
  map<int, int> pl;
  for (int i = 0; i < (int)(n); i++) {
    int x;
    cin >> x;
    for (int i = 2; i * i <= x; i++) {
      while (x % i == 0) {
        pl[i]++;
        x /= i;
      }
    }
    if (x != 1) pl[x]++;
  }
  long long int sum = 1;
  for (__typeof((pl).begin()) it = (pl).begin(); it != (pl).end(); ++it)
    (sum *= comb(it->second + n - 1, n - 1)) %= MOD;
  cout << sum << endl;
  return 0;
}
