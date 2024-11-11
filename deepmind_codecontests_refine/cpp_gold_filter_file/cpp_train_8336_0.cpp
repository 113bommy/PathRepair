#include <bits/stdc++.h>
using namespace std;
class bit {
  vector<int> v;

 public:
  bit() { v.assign(1000000, 0); }

 public:
  int rsq(int idx) {
    int temp = 0;
    for (; idx; idx -= (idx & -(idx))) {
      temp += v[idx];
    }
    return temp;
  }

 public:
  int rsq(int a, int b) { return rsq(b) - rsq(a - 1); }

 public:
  void update(int idx) {
    for (; idx < v.size(); idx += (idx & -(idx))) {
      v[idx] += 1;
    }
  }
};
class trie {
  class node {
   public:
    int a[10];

   public:
    bool endHere;

   public:
    node() {
      for (int i = 0; i < 10; ++i) a[i] = 0;
      endHere = false;
    };
  };
  vector<node> v;

 public:
  trie() { v.push_back(node()); }

 public:
  void insert(string s) {
    int idx = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      int val = s[i] - '0';
      if (!v[idx].a[val]) {
        v.push_back(node());
        v[idx].a[val] = v.size() - 1;
      }
      idx = v[idx].a[val];
    }
  }
};
vector<long long> v, back;
vector<vector<int> > adjlist;
int n, m, u_, v_, c_, testcase, ans, k, minx = 1 << 30, maxn = -(1 << 30), sum,
                                        cnt, query, type, offset;
int a, b, temp, pos, lim, curr;
string s, t, p;
bool flag, bl, flipflop;
char c;
set<int> uni;
map<long long, long long> dict;
bitset<10000000> vis;
long long ago;
long long dp[1000];
int main() {
  dp[0] = 1;
  for (int i = 1; i < 40; ++i) {
    dp[i] = dp[i - 1] * 2;
  }
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    ++dict[v[i]];
  }
  for (int i = 0; i < n; ++i) {
    bl = false;
    for (int j = 1; j < 40; ++j) {
      if (dp[j] < v[i]) continue;
      long long need = dp[j] - v[i];
      if (need != v[i] && dict.find(need) != dict.end()) {
        bl = true;
        break;
      }
      if (need == v[i] && dict.find(need) != dict.end() && dict[need] >= 2) {
        bl = true;
        break;
      }
    }
    if (!bl) ++cnt;
  }
  cout << cnt;
}
