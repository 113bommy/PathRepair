#include <bits/stdc++.h>
using namespace std;
int vis[10];
struct no {
  int v;
  string s;
  bool operator<(const no& p) { return v < p.v; }
};
vector<no> ve[4];
int main() {
  int n, m;
  scanf("%d", &n);
  no te;
  for (int i = 0; i < n; i++) {
    cin >> te.v >> te.s;
    ve[te.s.size()].push_back(te);
  }
  int t1 = 500005, t2 = 500005, t3 = 500005;
  for (int i = 0; i < ve[1].size(); i++) {
    if (ve[1][i].s[0] == 'A')
      t1 = min(t1, ve[1][i].v);
    else if (ve[1][i].s[0] == 'B')
      t2 = min(t2, ve[1][i].v);
    else
      t3 = min(t3, ve[1][i].v);
  }
  int ans1 = t1 + t2 + t3;
  int ans2 = 500005;
  int p[10];
  p[0] = 500005;
  p[1] = 500005;
  p[2] = 500005;
  for (int i = 0; i < ve[2].size(); i++) {
    string ss = ve[2][i].s;
    int v = ve[2][i].v;
    for (int j = 0; j < ss.size(); j++) {
      p[ss[j] - 'A'] = min(p[ss[j] - 'A'], v);
    }
  }
  for (int i = 0; i < ve[2].size(); i++) {
    string ss = ve[2][i].s;
    int v = ve[2][i].v;
    memset(vis, 0, sizeof(vis));
    for (int j = 0; j < ss.size(); j++) {
      vis[ss[j] - 'A'] = 1;
    }
    for (int j = 0; j < 3; j++) {
      if (!vis[j]) {
        if (j == 0) v += min(t1, p[0]);
        if (j == 1) v += min(t2, p[1]);
        if (j == 2) v += min(t3, p[2]);
        break;
      }
    }
    ans2 = min(ans2, v);
  }
  int ans3 = 500005;
  for (int i = 0; i < ve[3].size(); i++) ans3 = min(ans3, ve[3][i].v);
  int ans = min(ans1, ans2);
  ans = min(ans, ans3);
  if (ans == 500005)
    printf("-1\n");
  else
    cout << ans << endl;
  return 0;
}
