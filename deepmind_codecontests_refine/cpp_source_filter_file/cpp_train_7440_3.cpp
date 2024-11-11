#include <bits/stdc++.h>
using namespace std;
const long long MUL = rand() % 350 + 257;
const long long MOD = 1e9 + 21;
class HASH {
 public:
  vector<long long> hash, pows;
  HASH(const string &s, const long long &mod, const long long &mul);
  long long val();

 private:
  long long mod, mul;
  unsigned int size;
  void fill_pows();
};
void HASH::fill_pows() {
  pows[0] = 1;
  pows[1] = mul;
}
HASH::HASH(const string &s, const long long &mod, const long long &mul) {
  this->mul = mul;
  this->mod = mod;
  size = s.size();
  hash.resize(size);
  pows.resize(size);
  if (s[0] >= 'a' && s[0] <= 'z') {
    hash[0] = (s[0] - 'a' + 1);
  } else if (s[0] >= 'A' && s[0] <= 'Z') {
    hash[0] = (s[0] - 'A' + 1 + 30);
  } else {
    hash[0] = (s[0] - '0' + 1 + 60);
  }
  if (s[1] >= 'a' && s[1] <= 'z') {
    hash[1] = (hash[0] * mul + (s[1] - 'a' + 1)) % mod;
  } else if (s[1] >= 'A' && s[1] <= 'Z') {
    hash[1] = (hash[0] * mul + (s[1] - 'A' + 1 + 30)) % mod;
  } else {
    hash[1] = (hash[0] * mul + (s[1] - '0' + 1 + 60)) % mod;
  }
  fill_pows();
}
long long HASH::val() { return hash[1]; }
vector<int> used;
vector<int> res;
void dfs(int v, map<long long, vector<pair<long long, long long>>> &mp) {
  while (!mp[v].empty()) {
    auto t = mp[v].back();
    mp[v].pop_back();
    if (!used[t.second] && t.first != -1) {
      used[t.second] = 1;
      dfs(t.first, mp);
    }
  }
  res.push_back(v);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(time(0));
  int n;
  cin >> n;
  map<long long, vector<pair<long long, long long>>> mp;
  map<long long, string> vert;
  int cnt = 0;
  map<long long, long long> vused;
  long long thash = 0;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    long long v1 = HASH(s.substr(0, 2), MOD, MUL).val();
    long long v2 = HASH(s.substr(1, 2), MOD, MUL).val();
    vert[v1] = s.substr(0, 2);
    vert[v2] = s.substr(1, 2);
    mp[v1].push_back({v2, cnt++});
    thash = v1;
    if (vused.find(v1) == vused.end()) vused[v1] = 0;
    vused[v2]++;
  }
  long long s = -1;
  for (auto i : vused) {
    if (mp[i.first].size() - i.second == 1) {
      if (s == -1) {
        s = i.first;
      } else {
        cout << "NO";
        return 0;
      }
    } else if (mp[i.first].size() - i.second > 1) {
      cout << "NO";
      return 0;
    }
  }
  if (s == -1) s = thash;
  used.assign(cnt + 1, 0);
  dfs(s, mp);
  for (auto i : used) {
    if (i == 0) {
      cout << "NO";
      return 0;
    }
  }
  reverse(res.begin(), res.end());
  cout << "YES" << endl;
  cout << vert[res[0]][0];
  for (auto i : res) {
    cout << vert[i][1];
  }
  return 0;
}
