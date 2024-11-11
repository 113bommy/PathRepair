#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 1;
int n, cnt = 0, tree[maxn * 9][9], sum[maxn];
string s[maxn];
void insert(string x) {
  int u = 0;
  for (int i = 0; i < x.size(); ++i) {
    int t = x[i] - '0';
    if (!tree[u][t]) tree[u][t] = ++cnt;
    u = tree[u][t];
  }
  sum[u]++;
}
void del(string x) {
  int u = 0;
  for (int i = 0; i < x.size(); ++i) u = tree[u][x[i] - '0'];
  sum[u]--;
}
bool check(string x) {
  int u = 0;
  for (int i = 0; i < x.size(); ++i) u = tree[u][x[i] - '0'];
  return !sum[u];
}
string query(string x) {
  for (int len = 1; len <= 9; ++len)
    for (int i = 0; i + len <= x.size(); ++i) del(x.substr(i, len));
  for (int len = 1; len <= 9; ++len)
    for (int i = 0; i + len <= x.size(); ++i) {
      if (check(x.substr(i, len))) {
        string ans = x.substr(i, len);
        for (int len = 1; len <= 9; ++len)
          for (int i = 0; i + len <= x.size(); ++i) insert(x.substr(i, len));
        return ans;
      }
    }
}
int main() {
  scanf("%d", &n);
  for (int k = 1; k <= n; ++k) {
    cin >> s[k];
    for (int len = 1; len <= 9; ++len)
      for (int i = 0; i + len <= s[k].size(); ++i) insert(s[k].substr(i, len));
  }
  for (int i = 1; i <= n; ++i) cout << query(s[i]) << endl;
}
