#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e6 + 5, INF = 1e9 + 1, SQ = 375, base = 100,
                    MOD = 610612741;
map<vector<long long int>, int> mp, htoi;
vector<long long int> hash_table = {402653189, 805306457, 610612741};
string s;
vector<long long int> ps[N];
long long int p[N][5];
vector<long long int> do_hash(string &s) {
  long long int tp = 0, MOD;
  vector<long long int> ans;
  for (int j = 0; j < hash_table.size(); j++) {
    tp = 0;
    MOD = hash_table[j];
    for (int i = 0; i < s.size(); i++)
      tp += p[s.size() - i - 1][j] * s[i], tp %= MOD;
    ans.push_back(tp);
  }
  return ans;
}
vector<long long int> phash(int l, int r) {
  vector<long long int> ans;
  long long int MOD, tp;
  for (int i = 0; i < hash_table.size(); i++) {
    MOD = hash_table[i];
    ans.push_back(
        (ps[r][i] - (l ? (ps[l - 1][i] * p[r - l + 1][i]) % MOD : 0) + MOD) %
        MOD);
  }
  return ans;
}
int main() {
  for (int i = 0; i < hash_table.size(); i++) p[0][i] = 1;
  for (int i = 1; i < N; i++)
    for (int j = 0; j < hash_table.size(); j++)
      p[i][j] = (p[i - 1][j] * base) % hash_table[j];
  long long int n, k, g;
  cin >> n >> k >> s;
  s += s;
  cin >> g;
  string ts;
  vector<long long int> tp;
  for (int i = 0; i < g; i++) {
    cin >> ts;
    tp = do_hash(ts);
    ++mp[tp];
    htoi[tp] = i + 1;
  }
  for (int i = 0; i < hash_table.size(); i++) ps[0].push_back(s[0]);
  for (int i = 1; i < s.size(); i++) {
    for (int j = 0; j < hash_table.size(); j++) {
      ps[i].push_back((ps[i - 1][j] * base + s[i]) % hash_table[j]);
    }
  }
  vector<vector<long long int> > rec;
  for (int j = 0; j < k; j++) {
    for (int i = j; i < n * k + j; i += k) {
      tp = phash(i, i + k - 1);
      if (!mp[tp]) break;
      --mp[tp];
      rec.push_back(tp);
    }
    if (rec.size() >= n) {
      cout << "YES\n";
      for (auto x : rec) cout << htoi[x] << ' ';
      return 0;
    }
    for (auto x : rec) ++mp[x];
    rec.clear();
  }
  cout << "NO\n";
  return 0;
}
