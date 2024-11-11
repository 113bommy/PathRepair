#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 500, M = N * 10;
char s[M];
int stk[M], top, kick[M], f[M][10], cnt, n, q, l, r, fst[M];
struct link {
  link *pre, *nxt;
  int c;
} pool[M], *p = pool, *hd = ++p, *tl = ++p;
void cut(link *p) {
  if (!p) return;
  if (p->pre) p->pre->nxt = p->nxt;
  if (p->nxt) p->nxt->pre = p->pre;
}
void push(int v) {
  stk[++top] = v;
  while (top > 1 && stk[top - 1] > stk[top])
    kick[stk[top - 1]] = min(kick[stk[top - 1]], cnt), stk[top - 1] = stk[top],
                   top--;
}
void init(void) {
  tl->pre = hd, tl->c = hd->c = -1;
  for (int i = 0; i < n; i++) {
    kick[i] = 2147483647;
    *(++p) = (link){tl->pre, tl, i}, tl->pre->nxt = p, tl->pre = p;
    if (!(hd->nxt)) hd->nxt = p;
  }
  while (true) {
    link *node = hd->nxt, *lst = NULL, *up = hd;
    int to = 1;
    while (node) {
      push(node->c);
      if (node->c != -1) {
        ++cnt;
        if (!fst[node->c]) fst[node->c] = cnt;
        if (isdigit(s[node->c])) {
          f[cnt][s[node->c] - '0']++;
          if (s[node->c] == '0')
            cut(node);
          else
            s[node->c]--;
          lst = NULL;
        } else {
          cut(lst), lst = node;
          if (s[node->c] == '<')
            to = -1;
          else
            to = 1;
        }
      }
      up = node;
      if (to < 0)
        node = node->pre;
      else
        node = node->nxt;
    }
    if (up == tl) {
      fst[n] = ++cnt;
      break;
    } else
      cut(hd->nxt), top = 0;
  }
}
int main(void) {
  scanf("%d%d", &n, &q);
  scanf("%s", s);
  init();
  for (int i = 2; i <= cnt; i++)
    for (int j = 0; j < 10; j++) f[i][j] += f[i - 1][j];
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &l, &r);
    l--, r--;
    int hd = fst[l], tl = min(kick[l], fst[r + 1] - 1);
    for (int i = 0; i < 10; i++) printf("%d ", f[tl][i] - f[hd - 1][i]);
    puts("");
  }
  return 0;
}
