#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int base = 29;
int n, len;
long long Val[101010], Hash[101010], POW[101010], p[101010];
string s, m[101010];
vector<int> contains[101010], appear[101010];
int res[101010], k[101010];
long long getHash(int i, int j) {
  return (Hash[j] - Hash[i - 1] * POW[j - i + 1] + MOD * MOD) % MOD;
}
void GoHome() {
  cin >> s >> n;
  len = s.size();
  s = '~' + s;
  Hash[0] = 0;
  POW[0] = 1;
  for (int i = (1); i <= (len); ++i) {
    POW[i] = POW[i - 1] * 2ll % MOD;
    Hash[i] = (Hash[i - 1] * base + (s[i] - 'a')) % MOD;
  }
  for (int i = (1); i <= (n); ++i) {
    cin >> k[i] >> m[i];
    Val[i] = 0;
    int sz = m[i].size();
    for (int j = 0; j < (sz); ++j)
      Val[i] = (Val[i] * base + (m[i][j] - 'a')) % MOD;
    contains[sz].push_back(i);
    res[i] = len + 1;
  }
  for (int i = (1); i <= (len); ++i)
    if (contains[i].size()) {
      sort(contains[i].begin(), contains[i].end(),
           [](int x, int y) { return Val[x] < Val[y]; });
      int sz = contains[i].size();
      for (int j = 0; j < (sz); ++j) {
        appear[j].clear();
        p[j] = Val[contains[i][j]];
      }
      for (int j = (1); j <= (n - i + 1); ++j) {
        long long val = getHash(j, j + i - 1);
        int pos = lower_bound(p, p + sz, val) - p;
        if (pos < sz && p[pos] == val) {
          appear[pos].push_back(j);
        }
      }
      for (int j = 0; j < (sz); ++j) {
        int id = contains[i][j];
        for (int t = (k[id]); t <= ((int)appear[j].size()); ++t) {
          res[id] = min(res[id], appear[j][t - 1] + i - appear[j][t - k[id]]);
        }
      }
    }
  for (int id = (1); id <= (n); ++id) {
    if (res[id] == len + 1) res[id] = -1;
    cout << res[id] << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  GoHome();
}
