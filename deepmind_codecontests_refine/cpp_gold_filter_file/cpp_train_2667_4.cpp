#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 4005;
int fact[N], C[N][N];
int DigitCountIsOdd(int x) {
  int Count = 0;
  while (x) {
    Count++;
    x /= 10;
  }
  return (Count % 2 == 1);
}
int value(int x) {
  int Ans = 0, f = 1;
  while (x) {
    Ans += x % 10 * (11 + f) % 11;
    Ans = (Ans + 11) % 11;
    f = -f;
    x /= 10;
  }
  return Ans;
}
int Divide(int n, int k) {
  if (k == 0) {
    if (n) return 0;
    return 1;
  }
  return C[n + k - 1][k - 1];
}
int Candy(int n, int k) { return 1ll * fact[n] * Divide(n, k) % mod; }
void build() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = 1ll * fact[i - 1] * i % mod;
  C[0][0] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 0; j <= i; j++)
      if (j == 0)
        C[i][j] = 1;
      else if (j == i)
        C[i][j] = 1;
      else
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
}
void solve() {
  int n;
  cin >> n;
  vector<int> odd, even;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (DigitCountIsOdd(x))
      odd.push_back(value(x));
    else
      even.push_back((11 - value(x)) % 11);
  }
  int x = odd.size(), y = even.size();
  int dpOdd[x + 1][x + 1][11], dpEven[y + 1][y + 1][11];
  memset(dpOdd, 0, sizeof(dpOdd));
  memset(dpEven, 0, sizeof(dpEven));
  dpOdd[0][0][0] = 1;
  for (int i = 1; i <= x; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k <= 10; k++) {
        int w = odd[i - 1] % 11;
        if (j > 0) dpOdd[i][j][k] += dpOdd[i - 1][j - 1][(k - w + 11) % 11];
        if (i - 1 >= j) dpOdd[i][j][k] += dpOdd[i - 1][j][(k + w + 11) % 11];
        dpOdd[i][j][k] %= mod;
      }
  dpEven[0][0][0] = 1;
  for (int i = 1; i <= y; i++)
    for (int j = 0; j <= i; j++)
      for (int k = 0; k <= 10; k++) {
        int w = even[i - 1] % 11;
        if (j > 0) dpEven[i][j][k] += dpEven[i - 1][j - 1][(k - w + 11) % 11];
        if (i - 1 >= j) dpEven[i][j][k] += dpEven[i - 1][j][(k + w + 11) % 11];
        dpEven[i][j][k] %= mod;
      }
  int ans = 0, ff = 1ll * fact[(x + 1) / 2] * fact[x - (x + 1) / 2] % mod;
  int PartEven = x / 2 + 1, PartOdd = x + 1 - PartEven;
  for (int NumEvenPositive = 0; NumEvenPositive <= y; NumEvenPositive++)
    for (int remainderOdd = 0; remainderOdd < 11; remainderOdd++) {
      int remainderEven = (11 - remainderOdd) % 11;
      int way = 1ll * ff * Candy(NumEvenPositive, PartEven) % mod *
                Candy(y - NumEvenPositive, PartOdd) % mod;
      ans += 1ll * dpOdd[x][(x + 1) / 2][remainderOdd] *
             dpEven[y][NumEvenPositive][remainderEven] % mod * way % mod;
      ans %= mod;
    }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  build();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
