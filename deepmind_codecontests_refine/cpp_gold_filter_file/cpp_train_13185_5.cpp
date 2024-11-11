#include <bits/stdc++.h>
using namespace std;
int n, i, l, tot, node_cnt, j, L, k, p[100005], x, fail[100005], ans[100005],
    len[100005], U[100005], u, to[100005][26], v1[100005], v2[100005];
char t[100005], s[100005];
queue<int> q;
vector<int> gg[100005];
vector<int> ps[100005];
int cal() {
  int i = 2, j = 0, ret = 1e9;
  for (; i <= l; ++i) {
    while (j && t[i] != t[j + 1]) j = p[j];
    if (t[i] == t[j + 1]) ++j;
    p[i] = j;
  }
  tot = j = 0;
  for (i = 1; i <= L; ++i) {
    while (j && s[i] != t[j + 1]) j = p[j];
    if (s[i] == t[j + 1]) ++j;
    if (j == l) j = p[j], U[++tot] = i;
  }
  if (tot < k) return -1;
  for (i = k; i <= tot; ++i) {
    ret = min(ret, U[i] - U[i - k + 1] + l);
  }
  return ret;
}
void ins(int pos) {
  u = 0;
  for (int i = 1; i <= l; ++i) {
    t[i] -= 'a';
    if (!to[u][t[i]]) to[u][t[i]] = ++node_cnt;
    u = to[u][t[i]];
  }
  v1[u] = pos;
}
int main() {
  scanf("%s%d", s + 1, &n);
  L = strlen(s + 1);
  for (i = 1; i <= n; ++i) {
    scanf("%d%s", &k, t + 1);
    l = strlen(t + 1);
    if (l >= 200) {
      ans[i] = cal();
    } else {
      ins(i);
      v2[i] = k;
      len[i] = l;
    }
  }
  for (i = 0; i < 26; ++i) {
    if (to[0][i]) q.push(to[0][i]);
  }
  while (q.size()) {
    x = q.front();
    q.pop();
    for (i = 0; i < 26; ++i) {
      if (to[x][i])
        fail[to[x][i]] = to[fail[x]][i], q.push(to[x][i]);
      else
        to[x][i] = to[fail[x]][i];
    }
  }
  u = 0;
  for (i = 1; i <= L; ++i) {
    u = to[u][s[i] - 'a'];
    x = u;
    while (x) {
      if (v1[x]) ps[v1[x]].push_back(i);
      x = fail[x];
    }
  }
  for (i = 1; i <= n; ++i) {
    if (!ans[i]) {
      if (ps[i].size() < v2[i])
        ans[i] = -1;
      else {
        ans[i] = 1e9;
        for (j = v2[i] - 1; j < ps[i].size(); ++j) {
          ans[i] = min(ans[i], ps[i][j] - ps[i][j - v2[i] + 1] + len[i]);
        }
      }
    }
  }
  for (i = 1; i <= n; ++i) cout << ans[i] << "\n";
}
