#include <bits/stdc++.h>
using namespace std;
const int NMAX = 3e5 + 5;
const long long base = 5381;
const long long MOD = 1e9 + 7;
const int SMAX = 1e6 + 5;
int n, m;
string s[NMAX];
map<long long, int> cnt;
long long Pow(long long a, int k) {
  if (!k) return 1;
  long long tmp = Pow(a, k / 2) % MOD;
  tmp = (tmp * tmp) % MOD;
  return (k % 2 ? (tmp * a) % MOD : tmp);
}
void init() {
  for (int i = 1; i <= n; i++) {
    long long h = 0;
    for (int j = 0; j < s[i].size(); j++) {
      h = h * base + s[i][j] - 'a' + 1;
      h %= MOD;
    }
    cnt[h] = 1;
  }
}
bool solve(string t) {
  long long hashT = 0;
  for (int i = 0; i < t.size(); i++) {
    hashT = hashT * base + t[i] - 'a' + 1;
    hashT %= MOD;
  }
  for (int i = 0; i < t.size(); i++) {
    for (int j = 'a'; j <= 'c'; j++) {
      if (t[i] == j) continue;
      long long tmp =
          ((hashT + (j - t[i]) * Pow(base, t.size() - i - 1)) % MOD + MOD) %
          MOD;
      if (cnt[tmp]) return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  init();
  while (m--) {
    string t;
    cin >> t;
    cout << (solve(t) ? "YES" : "NO") << '\n';
  }
  return 0;
}
