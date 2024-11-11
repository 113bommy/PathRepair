#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 500;
const int maxm = 500000 + 10;
struct Edge {
  int next, v;
  Edge() {}
  Edge(int next, int v) : next(next), v(v) {}
} e[maxm << 1];
int n, m, len, timer, num;
int head[maxm], cnt;
int low[maxn], dfn[maxn], belo[maxn];
bool inst[maxn], used[maxn];
int st[maxm], top, q[maxm], front, tail;
char org[27], s[maxn], ans[maxn], res[maxn];
int val[128];
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
inline void AddEdge(int u, int v) {
  e[++cnt] = Edge(head[u], v);
  head[u] = cnt;
}
void tarjan(int u) {
  low[u] = dfn[u] = ++timer;
  st[++top] = u;
  inst[u] = 1;
  for (int i = head[u]; i; i = e[i].next) {
    int v = e[i].v;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (inst[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (low[u] == dfn[u]) {
    num++;
    int j;
    do {
      j = st[top--];
      belo[j] = num;
      inst[j] = 0;
    } while (j != u);
  }
}
inline bool judge(int n) {
  for (int i = 2; i <= (n << 1 | 1); i++)
    if (!dfn[i]) tarjan(i);
  for (int i = 2; i <= (n << 1); i += 2)
    if (belo[i] == belo[i + 1]) return 0;
  return 1;
}
inline char find(int pos, char c) {
  for (int i = pos + 1; i < len; i++)
    if (org[i] == c) return 'a' + i;
  return -1;
}
int main() {
  scanf("%s", org);
  len = strlen(org);
  for (int i = 0; i < len; i++) val[i + 'a'] = org[i] == 'V' ? 0 : 1;
  n = read(), m = read();
  char op1[10], op2[10];
  int a, b;
  while (m--) {
    a = read(), scanf("%s", op1);
    b = read(), scanf("%s", op2);
    a = a << 1 | (op1[0] != 'V');
    b = b << 1 | (op2[0] != 'V');
    AddEdge(a, b);
    AddEdge(b ^ 1, a ^ 1);
  }
  scanf("%s", s + 1);
  if (!judge(n)) {
    puts("-1");
    return 0;
  }
  bool exis = 0;
  res[1] = -1;
  for (int pos = n + 1; pos >= 1; pos--) {
    for (int a = pos << 1; a <= (pos << 1 | 1); a++) {
      strcpy(ans + 1, s + 1);
      if (pos <= n) {
        char tp = find(s[pos] - 'a', a & 1 ? 'C' : 'V');
        if (tp == -1) continue;
        ans[pos] = tp;
      }
      for (int i = pos + 1; i <= n; i++) ans[i] = 'a';
      bool flag = 1;
      memset(used, 0, sizeof(used));
      for (int i = 1, x; i <= n && flag; i++) {
        x = i << 1 | val[ans[i]];
        if (used[x]) continue;
        used[x] = 1;
        front = tail = 0;
        q[++tail] = x;
        while (front != tail) {
          x = q[++front];
          if (used[x ^ 1]) {
            flag = 0;
            break;
          }
          if ((x >> 1) <= pos && val[ans[x >> 1]] != (x & 1)) {
            flag = 0;
            break;
          }
          if ((x >> 1) > pos) {
            char tp = find(-1, x & 1 ? 'C' : 'V');
            if (tp == -1) {
              flag = 0;
              break;
            }
            ans[x >> 1] = tp;
          }
          for (int j = head[x]; j; j = e[j].next) {
            int v = e[j].v;
            if (!used[v]) {
              used[v] = 1;
              q[++tail] = v;
            }
          }
        }
      }
      if (!flag) continue;
      exis = 1;
      ans[n + 1] = '\0';
      if (res[1] == -1)
        strcpy(res + 1, ans + 1);
      else if (strcmp(res + 1, ans + 1))
        strcpy(res + 1, ans + 1);
    }
    if (exis) break;
  }
  if (exis)
    puts(res + 1);
  else
    puts("-1");
  return 0;
}
