#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, num[maxn], cnt[maxn];
string ans;
vector<string> g[5][maxn];
map<string, int> mp[5];
void query(int l, int r, int id) {
  cout << "? " << l << " " << r << endl;
  int len = r - l + 1;
  int num = len * (len + 1) / 2;
  string tmp;
  while (num--) {
    cin >> tmp;
    len = tmp.length();
    sort(tmp.begin(), tmp.end());
    g[id][len].push_back(tmp);
    mp[id][tmp]++;
  }
}
void get(string s) {
  int len = s.length();
  if (len == 1) return ans += s, void();
  for (int i = 0; i < len; i++) {
    num[s[i]] = 0;
  }
  for (int i = 0; i < len; i++) {
    num[s[i]]++;
  }
  for (int i = 0; i < len; i++) {
    if (cnt[s[i]] != num[s[i]]) return ans += s[i], void();
  }
}
signed main() {
  cin >> n;
  query(1, n, 1);
  if (n == 1) return cout << "! " << g[1][1][0], 0;
  query(2, n, 2);
  string s;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < g[1][i].size(); j++) {
      s = g[1][i][j];
      if (mp[1][s] != mp[2][s]) {
        get(s);
        break;
      }
    }
    cnt[ans[i - 1]]++;
  }
  cout << "! " << ans;
}
