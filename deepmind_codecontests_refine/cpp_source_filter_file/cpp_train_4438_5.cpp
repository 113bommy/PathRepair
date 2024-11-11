#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100005;
struct RollingHash {
  static const long long mo0 = 1000000007, mo1 = 1000000009;
  static long long mul0, mul1;
  static const long long add0 = 1000010007, add1 = 1003333331;
  static vector<long long> pmo[2];
  string s;
  int sz;
  vector<long long> hash_[2];
  void init(string s) {
    this->s = s;
    sz = (int)s.size();
    hash_[0].resize(sz + 1, 0), hash_[1].resize(sz + 1, 0);
    if (!mul0)
      mul0 = 10009 + (((long long)&mul0) >> 5) % 259,
      mul1 = 10007 + (((long long)&mul1) >> 5) % 257;
    if (pmo[0].empty()) pmo[0].push_back(1), pmo[1].push_back(1);
    for (int i = 0; i < (int)(sz); ++i)
      hash_[0][i + 1] = (hash_[0][i] * mul0 + add0 + s[i]) % mo0;
    for (int i = 0; i < (int)(sz); ++i)
      hash_[1][i + 1] = (hash_[1][i] * mul1 + add1 + s[i]) % mo1;
  }
  pair<long long, long long> hash(int l, int r) {
    if (l > r) return make_pair(0, 0);
    while (pmo[0].size() < r + 2)
      pmo[0].push_back(pmo[0].back() * mul0 % mo0),
          pmo[1].push_back(pmo[1].back() * mul1 % mo1);
    return make_pair(
        (hash_[0][r + 1] + (mo0 - hash_[0][l] * pmo[0][r + 1 - l] % mo0)) % mo0,
        (hash_[1][r + 1] + (mo1 - hash_[1][l] * pmo[1][r + 1 - l] % mo1)) %
            mo1);
  }
  pair<long long, long long> hash(string s) {
    init(s);
    return hash(0, (int)s.size() - 1);
  }
  static pair<long long, long long> concat(pair<long long, long long> L,
                                           pair<long long, long long> R,
                                           int RL) {
    while (pmo[0].size() < RL + 2)
      pmo[0].push_back(pmo[0].back() * mul0 % mo0),
          pmo[1].push_back(pmo[1].back() * mul1 % mo1);
    return make_pair((R.first + L.first * pmo[0][RL]) % mo0,
                     (R.second + L.second * pmo[1][RL]) % mo1);
  }
};
vector<long long> RollingHash::pmo[2];
long long RollingHash::mul0, RollingHash::mul1;
map<pair<long long, long long>, int> mp;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < (int)(n); ++i) {
    cin >> s[i];
  }
  vector<RollingHash> rh(n);
  for (int i = 0; i < (int)(n); ++i) {
    rh[i].hash(s[i]);
  }
  vector<map<pair<long long, long long>, int> > mm(n);
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = 0; j < (int)((int)(s[i]).size()); ++j) {
      for (int k = (int)(j + 1); k < (int)((int)(s[i]).size() + 1); ++k) {
        pair<long long, long long> res = rh[i].hash(j, k - 1);
        mp[res]++;
        mm[i][res]++;
      }
    }
  }
  bool flag = false;
  for (int i = 0; i < (int)(n); ++i) {
    flag = false;
    for (int l = (int)(1); l < (int)(10); ++l) {
      for (int j = 0; j < (int)(9); ++j) {
        pair<long long, long long> res = rh[i].hash(j, j + l - 1);
        if (mp[res] == mm[i][res]) {
          cout << s[i].substr(j, l) << "\n";
          flag = true;
          break;
        }
      }
      if (flag) {
        break;
      }
    }
  }
  return 0;
}
