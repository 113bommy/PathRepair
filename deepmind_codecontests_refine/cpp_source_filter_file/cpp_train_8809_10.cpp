#include <bits/stdc++.h>
using namespace std;
const long long int M = 1e9 + 7;
const long long int MOD = 1000003;
string s, s2;
long long int fact[MOD + 5], _fact[MOD + 5], n;
long long int power(long long int x, long long int n) {
  long long int a = x;
  long long int res = 1;
  while (n) {
    if (n & 1) {
      res = (res * a) % M;
    }
    a = (a * a) % M;
    n >>= 1;
  }
  return res;
}
void init() {
  fact[0] = 1;
  for (long long int i = 1; i < MOD; i++) {
    fact[i] = (fact[i - 1] * i) % M;
  }
  _fact[MOD - 1] = power(fact[MOD - 1], M - 2) % M;
  for (long long int i = MOD - 2; i >= 0; i--) {
    _fact[i] = ((i + 1) * _fact[i + 1]) % M;
  }
}
long long int solve(string str) {
  long long int cnt[400] = {0};
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a']++;
  }
  long long int res = 0;
  long long int perm = fact[n] % M;
  for (int i = 0; i < 400; i++) {
    perm = (perm * _fact[cnt[i]]) % M;
  }
  for (int i = 0; i < n; i++) {
    perm = (perm * _fact[n - i]) % M;
    perm = (perm * fact[n - i - 1]) % M;
    for (int j = 0; j < str[i] - 'a'; j++) {
      if (!cnt[j]) continue;
      perm = (perm * cnt[j]) % M;
      res = (res + perm) % MOD;
      perm = (perm * _fact[cnt[j]]) % M;
      perm = (perm * fact[cnt[j] - 1]) % M;
    }
    if (!cnt[str[i] - 'a']) break;
    perm = (perm * cnt[str[i] - 'a']) % MOD;
    cnt[str[i] - 'a']--;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init();
  int T;
  T = 1;
  while (T--) {
    cin >> s >> s2;
    n = s.length();
    cout << (solve(s2) - solve(s) - 1) % M << endl;
  }
}
