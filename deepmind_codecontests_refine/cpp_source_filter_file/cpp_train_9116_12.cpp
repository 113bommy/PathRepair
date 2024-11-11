#include <bits/stdc++.h>
using namespace std;
const int maxn = 5050;
const int maxm = 50;
map<string, int> name;
bool val[maxn][maxm];
int oper[maxn];
string x[maxn], y[maxn];
int n, m;
string s, ans_min = "", ans_max = "";
int cal(int a, int b) {
  int g[maxn], x0, y0, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (oper[i] == 0)
      ans += g[i] = val[i][a];
    else {
      x0 = x[i] == "?" ? b : g[name[x[i]]];
      y0 = y[i] == "?" ? b : g[name[y[i]]];
      if (oper[i] == 1) ans += g[i] = x0 & y0;
      if (oper[i] == 2) ans += g[i] = x0 | y0;
      if (oper[i] == 3) ans += g[i] = x0 ^ y0;
    }
  }
  return ans;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    name[s] = i;
    cin >> s >> s;
    if (s[0] == '0' || s[0] == '1') {
      oper[i] = 0;
      for (int j = 0; j < m; j++) val[i][j] = s[j] - '0';
    } else {
      x[i] = s;
      cin >> s;
      oper[i] = s == "AND" ? 1 : (s == "OR" ? 2 : 3);
      cin >> s;
      y[i] = s;
    }
  }
  for (int i = 0; i < m; i++) {
    int k0, k1;
    k0 = cal(i, 0);
    k1 = cal(i, 1);
    if (k0 <= k1)
      ans_min += '0';
    else
      ans_min += '1';
    if (k0 >= k1)
      ans_max += '0';
    else
      ans_max += '1';
  }
  cout << ans_min << endl << ans_max << endl;
  return 0;
}
