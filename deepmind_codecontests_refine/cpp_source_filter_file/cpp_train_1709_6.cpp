#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 2005;
long long n, k, f[N][N], s[N][N];
string S;
void add(long long &a, long long b) { a = (a + b) % MOD; }
void in() {
  cin >> n >> k;
  cin >> S;
  n = S.size(), S = ' ' + S;
}
void process() {
  f[0][0] = 1, s[0][0] = 1;
  for (long long i = 1; i <= n; i++)
    for (long long sum = 0; sum <= k; sum++) {
      add(f[i][sum], s[i - 1][sum] * (S[i] - 'a'));
      for (long long pref = 1; pref <= i; pref++) {
        if (sum < pref * (n - i + 1)) break;
        add(f[i][sum], f[i - pref][sum - pref * (n - i + 1)] * ('z' - S[i]));
      }
      s[i][sum] = s[i - 1][sum] + f[i][sum];
    }
  cout << s[n][k] << '\n';
}
int main() {
  if (fopen("trash.inp", "r"))
    freopen("trash.inp", "r", stdin), freopen("trash.out", "w", stdout);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  in();
  process();
}
