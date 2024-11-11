#include <bits/stdc++.h>
using namespace std;
const int size = 900000, mod = 777777777, inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int nex[2][4] = {0, 1, 0, -1, 1, 0, -1, 0};
int n, m, a, b, ar[size], ma[4][4];
int last;
struct node {
  int a, b, la, ra, len;
  long long f[4][4];
  node *l, *r;
} e[size];
void update(node *p) {
  node *l = p->l, *r = p->r;
  p->la = l->la, p->ra = r->ra, p->len = l->len + r->len;
  memset(p->f, 0, sizeof(p->f));
  for (int i = 1; i < 4; i++)
    if (l->la == 0 || l->la == i)
      for (int j = 1; j < 4; j++)
        if (l->ra == 0 || l->ra == j)
          for (int k = 1; k < 4; k++)
            if (r->la == 0 || r->la == k)
              for (int m = 1; m < 4; m++)
                if (r->ra == 0 || r->ra == m)
                  p->f[i][m] =
                      (p->f[i][m] + l->f[i][j] * ma[j][k] * r->f[k][m]) % mod;
}
node *build(int a, int b) {
  node *p = &e[last++];
  p->a = a;
  p->b = b;
  p->len = b - a + 1;
  if (a == b) {
    p->la = p->ra = 0;
    p->f[1][1] = p->f[2][2] = p->f[3][3] = 1;
    return p;
  }
  int mid = a + b >> 1;
  p->l = build(a, mid);
  p->r = build(mid + 1, b);
  update(p);
  return p;
}
void modify(int a, int b, int c, node *p) {
  if (a <= p->a && b >= p->b) {
    p->la = p->ra = c;
    memset(p->f, 0, sizeof(p->f));
    p->f[c][c] = 1;
    if (c == 0) p->f[1][1] = p->f[2][2] = p->f[3][3] = 1;
    return;
  }
  int mid = p->a + p->b >> 1;
  if (a <= mid)
    modify(a, b, c, p->l);
  else
    modify(a, b, c, p->r);
  update(p);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i < 4; i++)
    for (int j = 1; j < 4; j++) cin >> ma[i][j];
  node *p = build(1, n);
  while (m--) {
    long long ans = 0;
    cin >> a >> b;
    modify(a, a, b, p);
    for (int i = 1; i < 4; i++)
      if (ar[1] == 0 || ar[i] == i)
        for (int j = 1; j < 4; j++)
          if (ar[n] == 0 || ar[n] == j) ans += p->f[i][j];
    cout << ans % mod << endl;
  }
  return 0;
}
