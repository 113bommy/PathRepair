#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
const int NMAX = 600;
const long long UNDEFINED = -1;
long long fact[NMAX];
long long d[NMAX][NMAX];
long long A[NMAX][NMAX];
long long calc(int a, int b) {
  if (d[a][b] != UNDEFINED) return d[a][b];
  if (b == 0) {
    if (a == 0) return d[a][b] = 1;
    long long res = calc(a - 1, b);
    if (a >= 2) {
      res += calc(a - 2, b) * (a - 1);
    }
    res %= MOD;
    return d[a][b] = res;
  }
  if (a == 0) {
    return d[a][b] = fact[b];
  }
  long long res = 0;
  for (int bb = 0; bb <= b; ++bb) {
    res += calc(a - 1, b - bb) * A[b][bb];
    res %= MOD;
  }
  if (a >= 2) {
    for (int bb = 0; bb <= b; ++bb) {
      long long add = calc(a - 2, b - bb) * (a - 1) * A[b][bb];
      add %= MOD;
      if (bb > 0) add *= 2;
      res = (res + add) % MOD;
      if (bb > 1) {
        long long mul = (bb - 1) / 2;
        add = calc(a - 2, b - bb) * (a - 1) * A[b][bb];
        add %= MOD;
        add *= mul * 2;
        add %= MOD;
        res = (res + add) % MOD;
        if (bb % 2 == 0) {
          add = calc(a - 2, b - bb) * (a - 1) * A[b][bb];
          res = (res + add) % MOD;
        }
      }
    }
  }
  return d[a][b] = res % MOD;
}
void solve() {
  int n;
  cin >> n;
  int a = 0, b = 0;
  for (int i = 0; i < int(n); ++i) {
    int v;
    cin >> v;
    if (v == 1)
      ++a;
    else
      ++b;
  }
  for (int i = 0; i < int(NMAX); ++i)
    for (int j = 0; j < int(NMAX); ++j) d[i][j] = UNDEFINED;
  for (int i = 0; i < int(NMAX); ++i) {
    A[i][0] = 1;
    for (int j = 1; j <= int(i); ++j) {
      A[i][j] = (A[i][j - 1] * (i - j + 1)) % MOD;
    }
  }
  fact[0] = 1;
  for (int i = 1; i <= int(NMAX - 1); ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  cout << calc(a, b) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
