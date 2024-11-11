#include <bits/stdc++.h>
using std::max;
using std::min;
using std::reverse;
using std::vector;
const int MAXN = 5e5 + 20;
int read() {
  int x = 0;
  char c = getchar();
  bool f = 0;
  while (c < '0' || c > '9') (c == '-') ? f = 1, c = getchar() : c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (48 ^ c), c = getchar();
  return (f) ? -x : x;
}
void write(const int &x) {
  if (x / 10) write(x / 10);
  putchar('0' + x % 10);
}
void read_string(char *s) {
  char ch = getchar();
  while (ch < 'a' && ch > 'z') ch = getchar();
  int tot = 1;
  while (ch >= 'a' && ch <= 'z') s[tot++] = ch, ch = getchar();
}
const int MAXV = MAXN, MAXE = MAXN << 1;
namespace Graph {
int first[MAXV], tote;
struct edge {
  int to, nxt;
} e[MAXE];
inline void addedge(const int &u, const int &v) {
  ++tote, e[tote].to = v, e[tote].nxt = first[u], first[u] = tote;
  ++tote, e[tote].to = u, e[tote].nxt = first[v], first[v] = tote;
}
}  // namespace Graph
using namespace Graph;
int pi[MAXN], pi_backup[MAXN];
void Kmp(const int &n, const int &m, const int &k, const char *s, const char *t,
         int *rem) {
  pi[1] = 0;
  for (int i = 2; i <= m; ++i) {
    int j = pi[i - 1];
    while (j && t[j + 1] != t[i]) j = pi[j];
    pi[i] = (t[j + 1] == t[i]) ? j + 1 : 0;
  }
  for (int i = 1, j = 0; i <= n; ++i) {
    while (j && t[j + 1] != s[i]) j = pi[j];
    if (t[j + 1] == s[i]) ++j;
    if (j > k) j = pi[j];
    rem[i] = j;
    if (j == m) j = pi[j];
  }
}
void Build(const int &m) {
  for (int i = 1; i <= m; ++i) addedge(i, pi[i]);
}
void Backup(const int &m) {
  for (int i = 1; i <= m; ++i) pi_backup[i] = pi[i];
}
int fst[MAXN], lst[MAXN];
void dfs(const int &u, const int &fa) {
  for (int l = first[u]; l; l = e[l].nxt)
    if (e[l].to != fa)
      dfs(e[l].to, u), fst[u] = min(fst[u], fst[e[l].to]),
                       lst[u] = max(lst[u], lst[e[l].to]);
}
char s[MAXN], t[MAXN];
int pre[MAXN], suf[MAXN];
int cnt[MAXN];
int main() {
  int n = read(), m = read(), k = read();
  read_string(s), read_string(t);
  Kmp(n, m, k, s, t, suf);
  Build(m);
  reverse(s + 1, s + 1 + n), reverse(t + 1, t + 1 + m);
  Kmp(n, m, k, s, t, pre);
  reverse(pre + 1, pre + 1 + n);
  if (m <= k)
    for (int i = m; i <= n; ++i)
      if (suf[i] == m) {
        int start_L = max(1, i - k + 1), start_R = start_L + k;
        int start_R2 = min(i - m + 1, n - k + 1),
            start_L2 = start_R2 - 1 - k + 1;
        if (start_R + k - 1 > n && start_L2 < 1)
          continue;
        else {
          putchar('Y'), putchar('e'), putchar('s'), putchar('\n');
          if (start_R + k - 1 > n)
            write(start_L2), putchar(' '), write(start_R2);
          else
            write(start_L), putchar(' '), write(start_R);
          return 0;
        }
      }
  if (n - k + 1 > k) {
    pi[0] = pi_backup[0] = -1;
    for (int i = pre[n - k + 1]; i != -1; i = pi[i]) ++cnt[i];
    for (int i = suf[k]; i != -1; i = pi_backup[i])
      if (cnt[m - i] > 0) {
        putchar('Y'), putchar('e'), putchar('s'), putchar('\n');
        write(1), putchar(' '), write(n - k + 1);
        return 0;
      }
  }
  for (int i = 0; i <= m; ++i) fst[i] = n + 1;
  for (int i = k; i <= n; ++i) fst[suf[i]] = min(fst[suf[i]], i);
  for (int i = 1; i <= n - k + 1; ++i) lst[pre[i]] = max(lst[pre[i]], i);
  dfs(0, -1);
  for (int i = 1; i <= m; ++i)
    if (i <= k && m - i <= k)
      if (fst[i] < lst[m - i]) {
        putchar('Y'), putchar('e'), putchar('s'), putchar('\n');
        write(fst[i] - k + 1), putchar(' '), write(lst[m - i]);
        return 0;
      }
  putchar('N'), putchar('o');
}
