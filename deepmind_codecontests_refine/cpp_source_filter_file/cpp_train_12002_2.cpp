#include <bits/stdc++.h>
using namespace std;
void print(vector<long long> a) {
  for (int i = 0; i < a.size(); i++) cout << a[i] << " \n"[i == a.size() - 1];
}
void print(vector<int> a) {
  for (int i = 0; i < a.size(); i++) cout << a[i] << " \n"[i == a.size() - 1];
}
void print(vector<pair<int, int> > a) {
  int cnt = 1;
  for (auto i : a)
    cout << cnt++ << ": {" << i.first << "," << i.second << "}\n";
}
void print(int a[], int l, int r) {
  for (int i = l; i <= r; i++) cout << a[i] << " \n"[i == r];
}
void print(long long a[], int l, int r) {
  for (int i = l; i <= r; i++) cout << a[i] << " \n"[i == r];
}
vector<pair<int, int> > getDiv(int a[], int l, int r) {
  vector<pair<int, int> > ret;
  for (int i = l; i <= r; i++) {
    int j = i;
    while (j + 1 <= r && a[j] == a[j + 1]) j++;
    int len = j - i + 1;
    ret.push_back(make_pair(a[i], len));
    i = j;
  }
  return ret;
}
vector<int> getPrimeInt(int Max_prime) {
  vector<int> ret;
  vector<bool> primes(Max_prime + 5, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i <= Max_prime; i++) {
    if (primes[i]) {
      ret.push_back(i);
      for (int j = 2; i * j <= Max_prime; j++) primes[i * j] = false;
    }
  }
  return ret;
}
vector<bool> getPrimeBool(int Max_prime) {
  vector<int> ret;
  vector<bool> primes(Max_prime + 5, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i <= Max_prime; i++) {
    if (primes[i]) {
      ret.push_back(i);
      for (int j = 2; i * j <= Max_prime; j++) primes[i * j] = false;
    }
  }
  return primes;
}
long long qpow(long long x, long long y) {
  long long temp = x;
  long long ans = 1;
  while (y) {
    if (y & 1) ans = (ans * temp);
    temp = (temp * temp);
    y >>= 1;
  }
  return ans;
}
long long qpow(long long x, long long y, long long MOD) {
  long long temp = x;
  long long ans = 1;
  while (y) {
    if (y & 1) ans = (ans * temp) % MOD;
    temp = (temp * temp) % MOD;
    y >>= 1;
  }
  return ans;
}
long long c[21][21];
long long fac[21];
void INIT() {}
int a[300050];
int dp[75][75][75][75];
int F[75][75];
int b[200050];
int keep[75][75];
void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= m; j++)
      for (int l = 0; l <= m / 2; l++)
        for (int o = 0; o <= k - 1; o++) dp[i][j][l][o] = -1e9;
  bool debug = false;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) cin >> b[j];
    int cnt = m / 2;
    dp[i][0][0][0] = 0;
    for (int j = 1; j <= m; j++) {
      int x = b[j];
      dp[i][j][0][0] = 0;
      for (int l = m / 2; l >= 1; l--) {
        for (int o = 0; o <= k - 1; o++) {
          if (debug)
            if (dp[i][j][l][o] < dp[i][j - 1][l][o])
              printf("(%d,%d,%d,%d) = %d\n", i, j, l, o, dp[i][j - 1][l][o]);
          dp[i][j][l][o] = max(dp[i][j][l][o], dp[i][j - 1][l][o]);
        }
        for (int o = 0; o <= k - 1; o++) {
          int tmp = ((o - b[j]) % k + k) % k;
          if (dp[i][j - 1][l - 1][tmp] != -1e9) {
            if (debug)
              printf("(%d,%d,%d,%d) = (%d,%d,%d,%d)+%d = %d+%d\n", i, j, l, o,
                     i, j - 1, l - 1, o, b[j], dp[i][j - 1][l - 1][tmp], b[j]);
            dp[i][j][l][o] =
                max(dp[i][j][l][o], dp[i][j - 1][l - 1][tmp] + b[j]);
          }
        }
      }
    }
    for (int o = 0; o <= k - 1; o++) {
      int tmp = 0;
      int j = m;
      for (int l = 0; l <= m / 2; l++) tmp = max(tmp, dp[i][j][l][o]);
      if (debug) cout << tmp << " \n"[o == k - 1];
      keep[i][o] = tmp;
    }
  }
  memset(F, 0, sizeof(F));
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k - 1; j++) F[i][j] = -1e9;
  if (debug) {
    cout << "\n";
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= k - 1; j++) cout << keep[i][j] << " \n"[j == k - 1];
  }
  for (int i = 0; i <= k - 1; i++) F[1][i] = keep[1][i];
  for (int i = 2; i <= n; i++)
    for (int j = 0; j <= k - 1; j++)
      for (int l = 0; l <= k - 1; l++) {
        F[i][(j + l) % k] = max(F[i][(j + l) % k], F[i - 1][j] + keep[i][l]);
      }
  if (debug) {
    cout << "\n";
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= k - 1; j++) cout << F[i][j] << " \n"[j == k - 1];
  }
  cout << F[n][0] << "\n";
}
int main() {
  { std::ios::sync_with_stdio(false); };
  INIT();
  { solve(); }
  return 0;
}
