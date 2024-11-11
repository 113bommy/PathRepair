#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007L;
const int SIZE = 102;
long long factors[SIZE], ar[SIZE], br[SIZE];
bool prime[SIZE];
std::vector<int> vec;
long long dp[SIZE][(1 << 16)], from[SIZE][(1 << 16)];
void precompute() {
  for (int i = 2; i <= 60; i++) {
    if (!prime[i])
      for (int j = i * i; j <= 60; j += i) prime[j] = 1;
  }
  for (int i = 2; i <= 60; i++)
    if (!prime[i]) vec.push_back(i);
  long long mask = 0;
  for (int i = 2; i <= 60; i++) {
    int val = i;
    mask = 0;
    for (int k = 0; k < (int)vec.size() && val > 1; k++) {
      int j = vec[k];
      if (prime[j] == 0 && val % j == 0) {
        while (val % j == 0) val = val / j;
        mask = (mask | (1 << k));
      }
    }
    factors[i] = mask;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(15);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> ar[i];
  precompute();
  for (int i = 0; i <= n; i++) {
    for (int mask = 0; mask < (1 << 16); mask++) dp[i][mask] = mod;
  }
  dp[0][0] = 0;
  int x;
  for (int i = 1; i <= n; i++) {
    for (int mask = 0; mask < (1 << 16); mask++) {
      for (int j = 1; j <= 60; j++) {
        if (!(mask & factors[j])) {
          x = (mask | factors[j]);
          if (dp[i][x] > dp[i - 1][mask] + abs(ar[i] - j)) {
            dp[i][x] = dp[i - 1][mask] + abs(ar[i] - j);
            from[i][x] = j;
          }
        }
      }
    }
  }
  x = (1 << 16) - 1;
  for (int mask = 0; mask < (1 << 16); mask++) {
    if (dp[n][x] > dp[n][mask]) x = mask;
  }
  for (int i = n; i > 0; i--) {
    br[i] = from[i][x];
    x ^= factors[from[i][x]];
  }
  for (int i = 1; i <= n; i++) cout << br[i] << " ";
  cout << endl;
  return 0;
}
