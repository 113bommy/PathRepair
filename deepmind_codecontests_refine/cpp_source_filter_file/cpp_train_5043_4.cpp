#include <bits/stdc++.h>
using namespace std;
const int inf = 1000000007;
int d[210][210][510][2];
short vis[210][210][510][2];
int q, n, k, b, cas;
int nex[210][22], out[210];
int fal[210];
int s[210];
int dp(int pos, int len, int w, int m) {
  w = min(w, k + 5);
  if (vis[pos][len][w][m] == cas) return d[pos][len][w][m];
  vis[pos][len][w][m] = cas;
  if (w > k) return d[pos][len][w][m] = 0;
  if (len == n) return d[pos][len][w][m] = 1;
  int res = 0;
  for (int i = 0; i < b; ++i) {
    if (m == 0 && i > s[len]) break;
    int nst = nex[pos][i], mm = m | i < s[len];
    int ww = w + out[nst];
    res += dp(nst, len + 1, ww, mm);
    if (res >= inf) res -= inf;
  }
  return d[pos][len][w][m] = res;
}
int nn;
void add(int len, int w) {
  int pos = 0, i = 0;
  while (i < len) {
    int ii = s[i++];
    if (!nex[pos][ii]) nex[pos][ii] = ++nn;
    pos = nex[pos][ii];
  }
  out[nn] += w;
}
void bfs() {
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 0; i < b; ++i) {
      if (!nex[x][i])
        nex[x][i] = nex[fal[x]][i];
      else {
        int y = nex[x][i];
        if (x == 0)
          fal[y] = 0;
        else
          fal[y] = nex[fal[x]][i];
        out[y] += out[fal[y]];
        q.push(y);
      }
    }
  }
}
int aa[210], bb[210];
int lena, lenb;
int down() {
  int res = 0;
  for (int pos = 0, i = 0; i < lena; ++i) {
    pos = nex[pos][aa[i]];
    res += out[pos];
  }
  return res <= k;
}
int ask() {
  ++cas;
  long long ans = 0;
  for (int i = 1; i < s[0]; ++i) ans += dp(nex[0][i], 1, out[nex[0][i]], 1);
  ans += dp(nex[0][s[0]], 1, out[nex[0][s[0]]], 0);
  for (int i = 1; i < n; ++i)
    for (int j = 1; j < b; ++j) ans += dp(nex[0][j], i + 1, out[nex[0][j]], 1);
  return ans % inf;
}
int main() {
  scanf("%d %d %d", &q, &b, &k);
  scanf("%d", &lena);
  for (int i = 0; i < lena; ++i) scanf("%d", &aa[i]);
  scanf("%d", &lenb);
  for (int i = 0; i < lenb; ++i) scanf("%d", &bb[i]);
  int len, w;
  while (q--) {
    scanf("%d", &len);
    for (int i = 0; i < len; ++i) scanf("%d", &s[i]);
    scanf("%d", &w);
    add(len, w);
  }
  bfs();
  cas = 1;
  n = lena;
  for (int i = 0; i < lena; ++i) s[i] = aa[i];
  int res = ask();
  cas = 2;
  n = lenb;
  for (int i = 0; i < lenb; ++i) s[i] = bb[i];
  int ans = ask();
  cout << (ans + down() + inf - res) % inf << endl;
  return 0;
}
