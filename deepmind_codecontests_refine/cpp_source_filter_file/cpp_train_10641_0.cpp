#include <bits/stdc++.h>
using namespace std;
const long long MOD = (long long)1e9 + 7;
int t, n;
string s;
set<int> vec[2], cnt[2][2][2][2];
set<string> st;
map<string, int> mp;
bool fun(int fst) {
  int cur = fst;
  bool flag = true;
  while (1) {
    cnt[fst][cur][cur][0].clear();
    if (cnt[fst][cur][cur ^ 1][0].size() > 0) {
      cnt[fst][cur][cur ^ 1][0].erase(cnt[fst][cur][cur ^ 1][0].begin());
    } else if (cnt[fst][cur][cur ^ 1][1].size() > 0) {
      cnt[fst][cur][cur ^ 1][1].erase(cnt[fst][cur][cur ^ 1][1].begin());
    } else if (cnt[fst][cur ^ 1][cur][1].size() > 0) {
      auto tmp = cnt[fst][cur ^ 1][cur][1].begin();
      vec[fst].insert(*tmp);
      cnt[fst][cur ^ 1][cur][1].erase(tmp);
    } else {
      if (cnt[fst][cur ^ 1][cur ^ 1][0].size() > 0) {
        flag = false;
      }
      if (cnt[fst][cur ^ 1][cur][0].size() > 0) flag = false;
      break;
    }
    cur = cur ^ 1;
  }
  return flag;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    vec[0].clear();
    vec[1].clear();
    st.clear();
    mp.clear();
    for (int u = 0; u < 2; u++)
      for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
          for (int v = 0; v < 2; v++) cnt[u][i][j][v].clear();
    for (int i = 0; i < n; i++) {
      cin >> s;
      st.insert(s);
      mp[s] = i;
      int len = s.length();
      if (1) {
        cnt[0][s[0] - '0'][s[len - 1] - '0'][0].insert(i);
        cnt[1][s[0] - '0'][s[len - 1] - '0'][0].insert(i);
      }
    }
    for (auto x : st) {
      string tmps = x;
      int len = x.length();
      reverse(tmps.begin(), tmps.end());
      if (x[0] == tmps[0]) continue;
      if (mp.count(tmps)) continue;
      cnt[0][x[0] - '0'][x[len - 1] - '0'][1].insert(mp[x]);
      cnt[0][x[0] - '0'][x[len - 1] - '0'][0].erase(mp[x]);
      cnt[1][x[0] - '0'][x[len - 1] - '0'][1].insert(mp[x]);
      cnt[1][x[0] - '0'][x[len - 1] - '0'][1].erase(mp[x]);
    }
    bool f0 = fun(0);
    bool f1 = fun(1);
    if (!f0 && !f1) {
      cout << -1 << "\n";
      continue;
    }
    if (f0 && f1) {
      if (vec[0].size() < vec[1].size()) {
        cout << vec[0].size() << "\n";
        for (auto x : vec[0]) {
          cout << x + 1 << " ";
        }
        cout << "\n";
      } else {
        cout << vec[1].size() << "\n";
        for (auto x : vec[1]) {
          cout << x + 1 << " ";
        }
        cout << "\n";
      }
    } else if (f0) {
      cout << vec[0].size() << "\n";
      for (auto x : vec[0]) {
        cout << x + 1 << " ";
      }
      cout << "\n";
    } else {
      cout << vec[1].size() << "\n";
      for (auto x : vec[1]) {
        cout << x + 1 << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
