#include <bits/stdc++.h>
const int mod = 998244353;
const int inf = 1000000009;
const long long INF = 1000000000000000009;
const long long big = 1000000000000000;
const long double eps = 0.0000000001;
using namespace std;
int DP[100005][101], S[100005];
int T[100005], W[105];
int G[100005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int n, k, len;
  cin >> n >> k >> len;
  for (int i = 1; i <= n; i++) cin >> T[i];
  int ile = 0, kto = -1;
  for (int i = 1; i <= len; i++) {
    if (T[i] != -1) {
      W[T[i]]++;
      if (W[T[i]] == 1) ile++;
      kto = T[i];
    }
  }
  if (ile <= 1) G[len] = kto;
  for (int i = len + 1; i <= n; i++) {
    if (T[i] != -1) {
      W[T[i]]++;
      if (W[T[i]] == 1) ile++;
      kto = T[i];
    }
    if (T[i - len] != -1) {
      W[T[i] - len]--;
      if (!W[T[i] - len]) ile--;
      if (!ile) kto = -1;
    }
    if (ile <= 1) G[i] = kto;
  }
  S[0] = 1;
  for (int i = 1; i <= n; i++) {
    int s = S[i - 1];
    for (int j = 1; j <= k; j++) {
      if (T[i] == -1 || T[i] == j) {
        DP[i][j] = s;
        if (G[i]) {
          if (G[i] == -1 || G[i] == j)
            DP[i][j] =
                ((long long int)DP[i][j] - S[i - len] + DP[i - len][j] + mod) %
                mod;
        }
      }
      S[i] = (S[i] + DP[i][j]) % mod;
    }
  }
  cout << S[n];
  return 0;
}
