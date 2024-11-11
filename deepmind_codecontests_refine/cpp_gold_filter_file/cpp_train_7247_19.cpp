#include <bits/stdc++.h>
using namespace std;
const int N = 10 * 20, P = 1000000009;
int n, m, top;
char str[200];
struct node {
  node *c[4], *fail;
  int len;
  int id;
};
int st, f[1020][N / 2 + 5][12];
node mem[N], *cur = mem, *q[N], *root, *nul = mem + 1;
int get(char x) {
  if (x == 'A') return 0;
  if (x == 'C') return 1;
  if (x == 'G') return 2;
  return 3;
}
node *newnode() {
  int i;
  cur++;
  cur->id = cur - mem;
  cur->len = 0;
  cur->fail = nul;
  for (i = 0; i < 4; i++) cur->c[i] = nul;
  top = cur->id;
  return cur;
}
void build_ac() {
  node *s, *v;
  int h, tail, i;
  q[h = tail = 1] = root;
  root->fail = root;
  while (h <= tail) {
    s = q[h++];
    for (i = 0; i < 4; i++) {
      if (s->c[i] == nul)
        s->c[i] = s->fail->c[i];
      else {
        q[++tail] = s->c[i];
        if (s != root) {
          v = s->fail;
          s->c[i]->fail = v->c[i];
          s->c[i]->len = max(s->c[i]->len, s->c[i]->fail->len);
        }
      }
    }
  }
  st = root->id;
}
void ins() {
  int idx, i;
  node *now = root;
  scanf("%s", str);
  for (i = 0; str[i]; i++) {
    idx = get(str[i]);
    if (now->c[idx] == nul) now->c[idx] = newnode();
    now = now->c[idx];
  }
  now->len = strlen(str);
}
void add(int &a, int b) {
  a += b;
  if (a >= P) a -= P;
}
int main() {
  int i, j, idx, v, p;
  scanf("%d%d", &n, &m);
  nul = newnode();
  root = nul;
  while (m--) {
    ins();
  }
  build_ac();
  f[0][root->id][0] = 1;
  int k, t;
  for (i = 1; i <= n; i++)
    for (j = st; j <= top; j++)
      for (k = 0; k < 10; k++)
        if (f[i - 1][j][k])
          for (t = f[i - 1][j][k], p = 0; p < 4; p++) {
            v = mem[j].c[p]->id;
            if (k < mem[v].len)
              add(f[i][v][0], t);
            else
              add(f[i][v][k + 1], t);
          }
  int ans = 0;
  for (i = st; i <= top; i++) add(ans, f[n][i][0]);
  cout << ans;
}
