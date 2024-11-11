#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int sum = 0, fg = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') fg = -1;
  for (; isdigit(c); c = getchar()) sum = (sum << 3) + (sum << 1) + (c ^ 0x30);
  return fg * sum;
}
const int maxn = 1e6 + 10;
struct node {
  int s1, s2, op, x;
} A[maxn];
char s[10];
int q[maxn], b[maxn], n;
void dfs(int now) {
  if (A[now].s1) dfs(A[now].s1);
  if (A[now].s2) dfs(A[now].s2);
  if (A[now].op == 1) A[now].x = A[A[now].s1].x & A[A[now].s2].x;
  if (A[now].op == 2) A[now].x = A[A[now].s1].x | A[A[now].s2].x;
  if (A[now].op == 3) A[now].x = A[A[now].s1].x ^ A[A[now].s2].x;
  if (A[now].op == 4) A[now].x = !A[A[now].s1].x;
}
void mark(int now) {
  if (!b[now]) return;
  if (A[now].op == 1) {
    if (A[A[now].s1].x) b[A[now].s2] = 1;
    if (A[A[now].s2].x) b[A[now].s1] = 1;
  }
  if (A[now].op == 2) {
    if (!A[A[now].s1].x) b[A[now].s2] = 1;
    if (!A[A[now].s2].x) b[A[now].s1] = 1;
  }
  if (A[now].op == 3) {
    b[A[now].s1] = b[A[now].s2] = 1;
  }
  if (A[now].op == 4) b[A[now].s1] = 1;
  if (A[now].s1) mark(A[now].s1);
  if (A[now].s2) mark(A[now].s2);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    if (s[0] == 'A') {
      int x = read(), y = read();
      A[i] = (node){x, y, 1, -1};
    }
    if (s[0] == 'O') {
      int x = read(), y = read();
      A[i] = (node){x, y, 2, -1};
    }
    if (s[0] == 'X') {
      int x = read(), y = read();
      A[i] = (node){x, y, 3, -1};
    }
    if (s[0] == 'N') {
      int x = read();
      A[i] = (node){x, 0, 4, -1};
    }
    if (s[0] == 'I') {
      int x = read();
      A[i] = (node){0, 0, 5, x};
      q[++q[0]] = i;
    }
  }
  dfs(1);
  b[1] = 1;
  mark(1);
  for (int i = 1; i <= q[0]; i++) printf("%d", A[1].x ^ b[q[i]]);
  printf("\n");
  return 0;
}
