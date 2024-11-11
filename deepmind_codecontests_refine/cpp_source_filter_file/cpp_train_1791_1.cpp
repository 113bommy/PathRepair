#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, top, pos, sl, sr, cnt_0, tot, ans, ans_i, ans_j;
char s[N];
struct myt {
  int c, id;
} ok[N];
struct Alexstrasza {
  int rst, id;
} stk[N];
struct Malygos {
  int cnt, dep, lp, rp;
} mat[N];
int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    s = (s << 3) + (s << 1) + ch - '0', ch = getchar();
  return s * w;
}
int main() {
  n = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i)
    if (s[i] == '(')
      ++sl;
    else
      ++sr;
  if (sl != sr) {
    printf("0\n");
    printf("1 1");
    return 0;
  }
  top = 0;
  for (int i = 1; i <= n; ++i)
    if (s[i] == '(')
      ++top;
    else {
      if (!top)
        pos = i;
      else
        --top;
    }
  for (int i = pos + 1; i <= n; ++i) ok[i - pos].c = s[i], ok[i - pos].id = i;
  for (int i = 1; i <= pos; ++i)
    ok[n - pos + i].c = s[i], ok[n - pos + i].id = i;
  top = 0;
  for (int i = 1; i <= n; ++i)
    if (ok[i].c == '(')
      ++top, stk[top].id = ok[i].id, stk[top].rst = 0;
    else {
      mat[++tot].cnt = stk[top].rst;
      mat[tot].dep = top;
      mat[tot].lp = stk[top].id;
      mat[tot].rp = ok[i].id;
      --top;
      ++stk[top].rst;
    }
  ans = 0;
  ans_i = ans_j = 1;
  cnt_0 = stk[0].rst;
  for (int i = 1; i <= tot; ++i) {
    if (mat[i].dep == 1) {
      if (mat[i].cnt + 1 > ans) {
        ans = mat[i].cnt + 1;
        ans_i = mat[i].lp;
        ans_j = mat[i].rp;
      }
    }
    if (mat[i].dep == 2) {
      if (cnt_0 + mat[i].cnt + 1 > ans) {
        ans = cnt_0 + mat[i].cnt + 1;
        ans_i = mat[i].lp;
        ans_j = mat[i].rp;
      }
    }
  }
  printf("%d\n", ans);
  printf("%d %d", ans_i, ans_j);
  return 0;
}
