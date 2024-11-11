#include <bits/stdc++.h>
constexpr int N = 200003;
int n, m, len, num[N << 1], nxt[N << 1];
char s1[N], s2[N], S[N << 1];
void mg() {
  memcpy(S + 1, s2 + 1, m), S[m + 1] = '$';
  memcpy(S + 2 + m, s1 + 1, n);
  len = n + m + 1;
}
void getnxt(char s[], int n) {
  nxt[1] = 0;
  for (int i = 2; i <= n; i++) {
    int j = nxt[i - 1];
    while (j && s[j + 1] != s[i]) j = nxt[j];
    if (s[j + 1] == s[i])
      nxt[i] = j + 1;
    else
      nxt[i] = 0;
  }
}
std::vector<int> G[N << 1];
void dfs(int u) {
  if (u >= m + 2) num[u] = 1;
  for (int i = 0; i < G[u].size(); ++i) {
    int v = G[u][i];
    dfs(v);
    num[u] += num[v];
  }
}
void getnum() {
  for (int i = 1; i <= len; ++i) G[nxt[i]].push_back(i);
  dfs(0);
}
long long cal() {
  long long ans = 1ll * n * m;
  for (int i = 1; i <= m; ++i) {
    if (S[i] == S[i + m + 1])
      --num[i];
    else
      break;
  }
  for (int p, i = 1; i <= m; ++i)
    if (nxt[i]) {
      p = i - nxt[i];
      ans -= num[p];
    }
  return ans;
}
int main() {
  scanf(" %s", s1 + 1);
  n = strlen(s1 + 1);
  scanf(" %s", s2 + 1);
  m = strlen(s2 + 1);
  mg();
  getnxt(S, len);
  getnum();
  printf("%lld\n", cal());
}
