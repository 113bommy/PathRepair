#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x * f;
}
int n, m, head[200005], cnt = 0, father1[200005], ans = 0;
struct Node1 {
  int u, v, w;
} Edges1[200005];
bool operator<(Node1 A, Node1 B) { return A.w < B.w; }
int findf(int x) {
  return (father1[x] == x) ? x : (father1[x] = findf(father1[x]));
}
int main() {
  memset(head, -1, sizeof(head));
  n = read(), m = read();
  for (int i = 1; i <= m; i++)
    Edges1[i].u = read(), Edges1[i].v = read(), Edges1[i].w = read();
  sort(Edges1 + 1, Edges1 + 1 + m);
  for (int i = 1; i <= n; i++) father1[i] = i;
  int cnt = 0, able = 0, uni = 0, from = 1;
  for (int i = 1; i <= m; i++) {
    int fu = findf(Edges1[i].u), fv = findf(Edges1[i].v);
    if (fu != fv) able++;
    if (i == m || Edges1[i + 1].w != Edges1[i].w) {
      for (int j = from; j <= i; j++) {
        int fu = findf(Edges1[j].u), fv = findf(Edges1[j].v);
        if (fu != fv) father1[fu] = fv, cnt++, uni++;
      }
      ans += able - uni;
      able = uni = 0, from = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
