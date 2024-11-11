#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int MAXA = 75;
int bitmaska[MAXA];
bool prost[MAXA];
int koliko[MAXA][2];
int dp[2][(1 << 20)];
int ADD(long long a, long long b) {
  if (a + b >= MOD) return (a + b) % MOD;
  if (a + b < 0) return (a + b + MOD) % MOD;
  return a + b;
}
int MUL(long long a, long long b) {
  a %= MOD;
  b %= MOD;
  return (a * 1LL * b) % MOD;
}
void ispis_prost() {
  for (int i = 0; i < MAXA; i++) {
    cout << i << " : " << prost[i] << " : " << bitset<20>(bitmaska[i]) << '\n';
  }
}
void unaprijed_izracunaj() {
  memset(prost, true, sizeof prost);
  memset(bitmaska, 0, sizeof bitmaska);
  int tr = 0;
  for (int i = 2; i < MAXA; i++) {
    if (!prost[i]) continue;
    for (int j = 1; j < MAXA; j++) {
      int x = j;
      while (!(x % i)) {
        x /= i;
        bitmaska[j] ^= (1 << tr);
      }
    }
    for (int j = i + i; j < MAXA; j += i) {
      prost[j] = false;
    }
    tr++;
  }
  for (int i = 0; i < MAXA; i++) {
    koliko[i][0] = 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  unaprijed_izracunaj();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    koliko[a][0] = ADD(koliko[a][0], koliko[a][1]);
    koliko[a][1] = koliko[a][0];
  }
  dp[0][0] = 1;
  for (int broj = 0; broj <= 70; broj++) {
    int sljedeci = (broj + 1) % 2;
    int trenutni = broj % 2;
    for (int maska = 0; maska < (1 << 20); maska++) {
      dp[sljedeci][maska] =
          ADD(dp[sljedeci][maska], MUL(dp[trenutni][maska], koliko[broj][0]));
      dp[sljedeci][maska ^ bitmaska[broj]] =
          ADD(dp[sljedeci][maska ^ bitmaska[broj]],
              MUL(dp[trenutni][maska], koliko[broj][1]));
    }
    for (int maska = 0; maska < (1 << 20); maska++) dp[trenutni][maska] = 0;
  }
  cout << dp[1][0] - 1 << '\n';
  return 0;
}
