#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
const int MOD = 998244353;
int n;
vector<int> v[5], ans;
string s[MAXN];
map<string, bool> mp;
int main() {
  int t, n;
  scanf("%d", &t);
  while (t--) {
    mp.clear();
    for (int i = 0; i <= 4; i++) v[i].clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      int len = s[i].size();
      if (s[i][0] == '0' && s[i][len - 1] == '0') {
        v[0].push_back(i);
      }
      if (s[i][0] == '0' && s[i][len - 1] == '1') {
        v[1].push_back(i);
        mp[s[i]] = 1;
      }
      if (s[i][0] == '1' && s[i][len - 1] == '0') {
        v[2].push_back(i);
        mp[s[i]] = 1;
      }
      if (s[i][0] == '1' && s[i][len - 1] == '1') {
        v[3].push_back(i);
      }
    }
    if (v[0].size() && v[3].size() && !v[1].size() && !v[2].size()) {
      printf("-1\n");
      continue;
    }
    if (v[0].size() && !v[3].size() && !v[1].size() && !v[2].size()) {
      printf("0\n");
      continue;
    }
    if (!v[0].size() && v[3].size() && !v[1].size() && !v[2].size()) {
      printf("0\n");
      continue;
    }
    int l1 = v[1].size();
    int l2 = v[2].size();
    ans.clear();
    if (l1 > l2) {
      int num = 0;
      for (int i = 0; i <= l2 - 1; i++) {
        string temp = s[v[2][i]];
        reverse(temp.begin(), temp.end());
        if (mp[temp]) {
          num++;
          mp[temp] = 0;
        }
      }
      int flag = 0;
      for (int i = 0; i <= l1 - 1; i++) {
        string temp = s[v[1][i]];
        if (!mp[temp]) continue;
        if (num < l2) {
          num++;
          continue;
        }
        if (!flag)
          flag = 1;
        else {
          flag = 0;
          ans.push_back(v[1][i]);
        }
      }
    } else {
      int num = 0;
      for (int i = 0; i <= l1 - 1; i++) {
        string temp = s[v[1][i]];
        reverse(temp.begin(), temp.end());
        if (!mp[temp]) {
          num++;
          mp[temp] = 0;
        }
      }
      int flag = 0;
      for (int i = 0; i <= l2 - 1; i++) {
        string temp = s[v[2][i]];
        if (mp[temp]) continue;
        if (num < l1) {
          num++;
          continue;
        }
        if (!flag)
          flag = 1;
        else {
          flag = 0;
          ans.push_back(v[2][i]);
        }
      }
    }
    int len = ans.size();
    printf("%d\n", len);
    for (int i = 0; i <= len - 1; i++) {
      printf("%d ", ans[i]);
    }
    puts("");
  }
}
