#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read(register T& t) {
  register T f = 1;
  register char ch = getchar();
  t = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') t = t * 10 + ch - '0', ch = getchar();
  t *= f;
  return t;
}
template <typename T, typename... Args>
inline void read(T& t, Args&... args) {
  read(t);
  read(args...);
}
const long long p = 998244353;
inline long long power(register long long x, register long long k = p - 2) {
  register long long re = 1;
  for (; k; k >>= 1, x = x * x % p)
    if (k & 1) re = re * x % p;
  return re;
}
int k;
char c[1005][1005];
int C[1005];
int trie[1005][14];
int fail[1005];
long long End[1005];
int tot;
void Insert(char* c, int val) {
  int p = 0;
  for (int i = 0; c[i]; i++) {
    if (trie[p][c[i] - 'a'] == 0) trie[p][c[i] - 'a'] = ++tot;
    p = trie[p][c[i] - 'a'];
  }
  End[p] += val;
}
void build_fail() {
  queue<int> q;
  for (int i = 0; i < 14; i++)
    if (trie[0][i]) q.push(trie[0][i]);
  while (q.size()) {
    int now = q.front();
    q.pop();
    End[now] += End[fail[now]];
    for (int i = 0; i < 14; i++)
      if (trie[now][i])
        fail[trie[now][i]] = trie[fail[now]][i], q.push(trie[now][i]);
      else
        trie[now][i] = trie[fail[now]][i];
  }
}
char s[400005];
int n;
long long pre[1005][15], posti[1005][15];
int NUM;
void solve(int pos, int id) {
  int p = pos;
  for (int i = id; s[i] != '?'; i++)
    p = trie[p][s[i] - 'a'], pre[pos][NUM] += End[p];
  posti[pos][NUM] = p;
}
long long f[1005][1 << 14];
int calc(int x) {
  int re = 0;
  for (int i = 0; i < 14; i++)
    if (x >> i & 1) re++;
  return re;
}
bool vis[1005][1 << 14];
long long dfs(int now, int S) {
  int num = calc(S);
  if (num == NUM) return pre[now][num];
  if (vis[now][S]) return f[now][S];
  vis[now][S] = 1;
  long long& ans = f[now][S];
  ans = -1e9;
  for (int i = 0; i < 14; i++)
    if (~S >> i & 1)
      ans =
          max(ans, pre[now][num] + dfs(trie[posti[now][num]][i], S | (1 << i)) +
                       End[trie[posti[now][num]][i]]);
  return ans;
}
int main() {
  read(k);
  for (int i = 1; i <= k; i++) {
    scanf("%s", c[i] + 1);
    read(C[i]);
    Insert(c[i] + 1, C[i]);
  }
  build_fail();
  scanf("%s", s + 1);
  n = strlen(s + 1);
  s[n + 1] = '?';
  s[0] = '?';
  for (int i = 0; i <= n; i++)
    if (s[i] == '?') {
      for (int j = 0; j <= tot; j++) solve(j, i + 1);
      NUM++;
    }
  NUM--;
  printf("%lld\n", dfs(0, 0));
  return 0;
}
