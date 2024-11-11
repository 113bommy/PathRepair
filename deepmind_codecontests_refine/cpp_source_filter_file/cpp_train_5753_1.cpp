#include <bits/stdc++.h>
using namespace std;
int n;
int ara[200010];
vector<int> sara;
int nxt1[200010], nxt2[200010];
int col[200010][2][2], cc;
int dp[200010][2][2];
bool is_fir[200010];
int func(int i, bool fir, bool last) {
  if (col[i][fir][last] == cc) {
    return dp[i][fir][last];
  }
  int ans = 0;
  if (fir) {
    if (nxt1[i] > i) {
      ans = max(ans, 1 + func(nxt1[i], 1, 0));
    }
    if (nxt2[i] > i) {
      if (is_fir[nxt2[i]]) {
        ans = max(ans, 1 + func(nxt2[i], 0, 0));
      }
      ans = max(ans, 1 + func(nxt2[i], 0, 1));
    }
  } else if (last) {
    if (nxt1[i] > i) {
      ans = max(ans, 1 + func(nxt1[i], 0, 1));
    }
  } else {
    if (nxt1[i] > i) {
      ans = max(ans, 1 + func(nxt1[i], 0, 0));
    }
    if (nxt2[i] > i) {
      if (is_fir[nxt2[i]]) {
        ans = max(ans, 1 + func(nxt2[i], 0, 0));
      }
      ans = max(ans, 1 + func(nxt2[i], 0, 1));
    }
  }
  col[i][fir][last] = cc;
  return dp[i][fir][last] = ans;
}
map<int, int> idx;
vector<int> pp[200010];
int findpp(int key, int val) {
  int pos = upper_bound(pp[key].begin(), pp[key].end(), val) - pp[key].begin();
  if (pos == pp[key].size()) {
    return -1;
  }
  return pp[key][pos];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; tt++) {
    cc = tt;
    cin >> n;
    idx.clear();
    sara.clear();
    for (int i = 0; i <= n - 1; i++) {
      cin >> ara[i];
      sara.push_back(ara[i]);
    }
    sort(sara.begin(), sara.end());
    sara.erase(unique(sara.begin(), sara.end()), sara.end());
    for (int i = 0; i <= (int)sara.size() - 1; i++) {
      idx[sara[i]] = i;
    }
    int m = sara.size();
    for (int i = 0; i <= m - 1; i++) {
      pp[i].clear();
    }
    for (int i = 0; i <= n - 1; i++) {
      int id = idx[ara[i]];
      pp[id].push_back(i);
    }
    for (int i = 0; i <= n - 1; i++) {
      is_fir[i] = 0;
    }
    for (int i = 0; i <= m - 1; i++) {
      is_fir[pp[i][0]] = 1;
    }
    for (int i = 0; i <= n - 1; i++) {
      int id = idx[ara[i]];
      nxt1[i] = findpp(id, i);
      if (id == m - 1) {
        nxt2[i] = -1;
      } else {
        nxt2[i] = findpp(id + 1, i);
      }
    }
    int ans = 1000000000;
    for (int i = 0; i <= n - 1; i++) {
      ans = min(ans, n - (1 + func(i, 0, 0)));
    }
    cout << ans << "\n";
  }
  return 0;
}
