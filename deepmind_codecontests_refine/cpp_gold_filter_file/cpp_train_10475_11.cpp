#include <bits/stdc++.h>
using namespace std;
const int N = 330;
const int mod = 1e9 + 7;
string s[N];
int st[N], en[N];
int n, m;
int len[N];
string fi[N], se[N];
bitset<20000> ok[N][14];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    len[i] = s[i].length();
    for (int k = 0; k < min((int)s[i].length(), 13); ++k) fi[i] += s[i][k];
    for (int k = max(0, (int)s[i].length() - 13); k < s[i].length(); ++k)
      se[i] += s[i][k];
    for (int j = 0; j < s[i].length(); ++j) {
      int val = 0;
      for (int k = 1; k <= 13 && k + j - 1 < (int)s[i].length(); ++k) {
        val = val * 2 + s[i][k + j - 1] - '0';
        if (val < 20000) ok[i][k][val] = 1;
      }
    }
  }
  cin >> m;
  for (int i = n + 1; i <= m + n; ++i) {
    int a, b;
    cin >> a >> b;
    int cur_ans = 0;
    for (int k = 1; k <= 13; ++k) {
      ok[i][k] |= (ok[a][k] | ok[b][k]);
      for (int pref = 1; pref <= k; ++pref) {
        if (se[a].length() < pref) continue;
        int p = (int)se[a].length() - pref;
        int val = 0;
        for (int u = 0; u < pref; ++u) val = val * 2 + se[a][p++] - '0';
        if ((int)fi[b].length() < k - pref) continue;
        for (int u = 0; u + pref < k; ++u) val = val * 2 + fi[b][u] - '0';
        if (val < 20000) ok[i][k][val] = 1;
      }
      if (ok[i][k].count() == (1 << k)) cur_ans = max(cur_ans, k);
    }
    int p = 0;
    fi[i] = fi[a];
    se[i] = se[b];
    while (fi[i].length() < 13 && p < fi[b].length()) fi[i] += fi[b][p++];
    p = (int)se[a].length() - 1;
    while (se[i].length() < 13 && p >= 0) {
      se[i] = se[a][p] + se[i];
      p--;
    }
    cout << cur_ans << '\n';
  }
  return 0;
}
