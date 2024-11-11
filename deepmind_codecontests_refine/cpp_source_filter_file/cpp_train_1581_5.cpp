#include <bits/stdc++.h>
using namespace std;
const int sq = 632, maxc = 26, maxn = 400 * 1000 + 10;
int n, m, type, dext = 1, idk, ted[maxn], cnt = 1, cur, p[maxn], ans[maxn],
                dt[maxn];
vector<int> ch[maxc], vec[maxn], dex, mat[maxn];
vector<pair<int, int>> q[maxn];
string t, s;
char tmp[maxn], c[maxn];
void build(int x) {
  s = "";
  cur = x;
  while (cur != 0) {
    s += c[cur];
    cur = p[cur];
  }
}
void search(int x, int h, int cn) {
  if (dex[cn] > 0) mat[x].push_back(dex[cn]);
  if (h == sq) return;
  for (auto w : vec[x]) {
    if (ch[c[w] - 'a'][cn] == 0) continue;
    search(w, h + 1, ch[c[w] - 'a'][cn]);
  }
}
void dfs(int x) {
  search(x, 0, 0);
  for (auto w : vec[x]) dfs(w);
}
void solve(int x) {
  for (auto w : mat[x]) ted[w]++;
  for (auto w : q[x]) ans[w.second] = ted[w.first];
  for (auto w : vec[x]) solve(w);
  for (auto w : mat[x]) ted[w]--;
}
int main() {
  ios::sync_with_stdio(0);
  for (int i = 0; i < maxc; i++) ch[i].push_back(0);
  dex.push_back(0);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &type);
    if (type == 1) {
      scanf("%c", &c[i + 1]);
      scanf("%c", &c[i + 1]);
      vec[0].push_back(i + 1);
    } else {
      scanf("%d %c", &idk, &c[i + 1]);
      p[i + 1] = idk;
      vec[idk].push_back(i + 1);
    }
  }
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %s", &idk, tmp);
    t = tmp;
    if ((((int)t.size())) > sq) {
      reverse(t.begin(), t.end());
      build(idk);
      cur = 0;
      dt[0] = -1;
      for (int j = 1; j < (((int)t.size())); j++) {
        while (cur >= 0 && t[cur] != t[j]) cur = dt[cur];
        dt[j] = ++cur;
      }
      cur = 0;
      for (int j = 0; j < (((int)s.size())); j++) {
        while (cur >= 0 && t[cur] != s[j]) cur = dt[cur];
        cur++;
        if (cur == (((int)t.size()))) {
          ans[i]++;
          cur = dt[cur];
        }
      }
    } else {
      cur = 0;
      for (auto w : t) {
        if (ch[w - 'a'][cur] == 0) {
          ch[w - 'a'][cur] = cnt++;
          for (int j = 0; j < maxc; j++) ch[j].push_back(0);
          dex.push_back(0);
        }
        cur = ch[w - 'a'][cur];
      }
      if (dex[cur] == 0) dex[cur] = dext++;
      q[idk].push_back({dex[cur], i});
    }
  }
  dfs(0);
  solve(0);
  for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
  return 0;
}
