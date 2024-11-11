#include <bits/stdc++.h>
using namespace std;
const int maxn = 50005;
const int Size = maxn * 30;
char str[maxn];
int nxt[Size][27];
int len[Size];
int par[Size];
int cur[Size];
int pos[Size];
int g[Size][12];
int rt, last, tol;
int L[12], R[12];
int newNode(int x) {
  len[++tol] = x;
  par[tol] = 0;
  memset(nxt[tol], 0, sizeof nxt[tol]);
  return tol;
}
void init() {
  tol = 0;
  last = rt = newNode(0);
}
void add(int c, int idx) {
  int p = last;
  int np = newNode(len[p] + 1);
  if (~idx) g[np][idx]++;
  while (p && !nxt[p][c]) {
    nxt[p][c] = np;
    p = par[p];
  }
  if (!p)
    par[np] = rt;
  else {
    int q = nxt[p][c];
    if (len[p] + 1 == len[q])
      par[np] = q;
    else {
      int nq = newNode(len[p] + 1);
      memcpy(nxt[nq], nxt[q], sizeof nxt[q]);
      par[nq] = par[q];
      par[q] = par[np] = nq;
      while (p && nxt[p][c] == q) {
        nxt[p][c] = nq;
        p = par[p];
      }
    }
  }
  last = np;
}
void ins(char s[], int idx) {
  for (int i = 0; s[i]; i++) {
    add(s[i] - 'a', idx);
  }
}
long long solve(int n) {
  for (int i = 0; i <= tol; i++) cur[i] = 0;
  for (int i = 1; i <= tol; i++) cur[len[i]]++;
  for (int i = 1; i <= tol; i++) cur[i] += cur[i - 1];
  for (int i = 1; i <= tol; i++) pos[cur[len[i]]--] = i;
  long long ans = 0;
  for (int i = tol; i >= 1; i--) {
    int u = pos[i];
    for (int j = 0; j <= n; j++) {
      g[par[u]][j] += g[u][j];
    }
    if (!g[u][0]) continue;
    int flag = 1;
    for (int j = 1; j <= n; j++) {
      if (g[u][j] < L[j] || g[u][j] > R[j]) {
        flag = 0;
        break;
      }
    }
    if (flag) ans += len[u] - len[par[u]];
  }
  return ans;
}
int main() {
  init();
  int n;
  scanf("%s%d", str, &n);
  ins(str, 0);
  for (int i = 1; i <= n; i++) {
    scanf("%s%d%d", str, &L[i], &R[i]);
    add(26, -1);
    ins(str, i);
  }
  cout << solve(n) << '\n';
  return 0;
}
