#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7;
int N;
int A[300010] = {0};
vector<int> P[300010];
long long fact[300010] = {0};
long long inv[300010] = {0};
long long F[300010] = {0};
long long power(long long a, long long k) {
  long long o = 1;
  for (; k > 0; k >>= 1) {
    if (k & 1) o = o * a % Mod;
    a = a * a % Mod;
  }
  return o;
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
  fact[0] = 1;
  for (int i = 1; i <= 300000; i++) fact[i] = fact[i - 1] * i % Mod;
  inv[300000] = power(fact[300000], Mod - 2);
  for (int i = 300000 - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % Mod;
  for (int i = 1; i <= N; i++) {
    int x = A[i];
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        int times = 0;
        for (; x % j == 0; x /= j, times++)
          ;
        P[j].push_back(times);
      }
    }
    if (x != 1) P[x].push_back(1);
  }
  F[1] = power(2, N - 1);
  for (int i = 2; i <= N; i++) {
    F[i] =
        (F[i - 1] -
         (fact[N - 1] * inv[i - 2] % Mod * inv[(N - 1) - (i - 2)] % Mod) * 2 +
         Mod * 2) %
        Mod;
  }
  long long Ans = 0;
  for (int i = 1; i <= 300000; i++) {
    sort(P[i].begin(), P[i].end());
    int S = P[i].size();
    if (S == 0) continue;
    for (int j = 1; j <= S; j++) {
      int t = P[i][S - j];
      Ans = (Ans + t * (F[j] -
                        (fact[N - 1] * inv[j - 1] % Mod *
                         inv[(N - 1) - (j - 1)] % Mod) +
                        Mod)) %
            Mod;
    }
  }
  cout << Ans << endl;
  return 0;
}
