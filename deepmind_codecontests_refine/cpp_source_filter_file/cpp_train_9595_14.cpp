#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
const int Mod = 998244353;
int N, K;
VI a;
VVI DP, sp;
VI cnt;
void ReadData();
int Solve(int x);
void WriteSol();
int main() {
  ReadData();
  sort(a.begin(), a.end());
  int bmax{a[N - 1] / (K - 1)};
  cnt = VI(bmax + 1);
  for (int x = 1; x <= bmax; ++x) cnt[x] = Solve(x);
  WriteSol();
  return 0;
}
void ReadData() {
  cin >> N >> K;
  a = VI(N + 1);
  sp = DP = VVI(N + 1, VI(K + 1));
  for (int i = 1; i <= N; ++i) cin >> a[i];
}
int Solve(int x) {
  DP[0][0] = sp[0][0] = 1;
  for (int i = 1; i <= N; ++i) sp[i][0] = 1;
  for (int k = 1; k <= K; ++k) {
    int prev{0};
    for (int i = 1; i <= N; ++i) {
      while (k > 1 && a[i] - a[prev + 1] >= x) ++prev;
      if (k > 1)
        DP[i][k] = sp[prev][k - 1];
      else
        DP[i][k] = 1;
      sp[i][k] = sp[i - 1][k] + DP[i][k];
      sp[i][k] = sp[i][k] >= Mod ? sp[i][k] - Mod : sp[i][k];
    }
  }
  return sp[N][K];
}
void WriteSol() {
  int s{0}, ans{0};
  for (int i = static_cast<int>(cnt.size()); i >= 1; --i) {
    ans = (1LL * ans + 1LL * i * ((cnt[i] - s + Mod) % Mod)) % Mod;
    s = cnt[i];
  }
  cout << ans << '\n';
}
