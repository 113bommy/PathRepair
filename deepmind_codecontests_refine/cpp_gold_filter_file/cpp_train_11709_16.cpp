#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = mod * mod;
const long double eps = 1e-8;
bitset<2001> trans(string s) {
  vector<int> num;
  for (int i = 0; i < s.size(); i++) {
    num.push_back(s[i] - '0');
  }
  reverse(num.begin(), num.end());
  bitset<2001> ans;
  for (int k = 0; num.size(); k++) {
    ans[k] = num[0] & 1;
    int sz = num.size();
    for (int i = 0; i < sz - 1; i++) {
      num[i] = (num[i] + (num[i + 1] & 1) * 10) >> 1;
    }
    num.back() >>= 1;
    if (num.back() == 0) num.pop_back();
  }
  return ans;
}
vector<bitset<2001> > b;
vector<int> fr;
vector<bitset<2000> > ids;
vector<int> out[2000];
void add(bitset<2001> &x, int id) {
  int loc;
  for (int i = 0; i < 2001; i++) {
    if (x[i]) {
      loc = i;
      break;
    }
  }
  bitset<2000> ans;
  ans[id] = 1;
  for (int i = 0; i < b.size(); i++) {
    if (fr[i] > loc) {
      fr.insert(fr.begin() + i, loc);
      b.insert(b.begin() + i, x);
      ids.insert(ids.begin() + i, ans);
      return;
    } else if (fr[i] == loc) {
      x ^= b[i];
      ans ^= ids[i];
      for (int j = loc + 1; j <= 2000; j++) {
        if (x[j]) {
          loc = j;
          break;
        }
      }
      if (loc == fr[i]) {
        for (int j = 0; j < id; j++) {
          if (ans[j]) {
            out[id].push_back(j);
          }
        }
        return;
      }
    }
  }
  fr.push_back(loc);
  b.push_back(x);
  ids.push_back(ans);
}
void solve() {
  int n;
  cin >> n;
  vector<bitset<2001> > m(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    m[i] = trans(s);
  }
  for (int i = 0; i < n; i++) {
    add(m[i], i);
  }
  for (int i = 0; i < n; i++) {
    cout << out[i].size();
    if (out[i].size()) {
      for (int j = 0; j < out[i].size(); j++) {
        cout << " " << out[i][j];
      }
    }
    cout << endl;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string l = to_string(2), r = to_string(1);
  solve();
  return 0;
}
