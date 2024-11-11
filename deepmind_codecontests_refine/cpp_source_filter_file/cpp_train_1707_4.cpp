#include <bits/stdc++.h>
using namespace std;
const int size = 210000, mod = 1e9 + 9, inf = 0x3f3f3f3f;
const long long llmod = 4294967296, llinf = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0), eps = 1e-6;
int month[2][13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                    0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int nex[2][8] = {-1, 0, 1, 0, -1, 1, 1, -1, 0, 1, 0, -1, 1, 1, 0, 0};
template <class T>
void inc(T& a, T b) {
  a = (a + b) % mod;
}
template <class T>
T modu(T a) {
  return (a % mod + mod) % mod;
}
template <class T>
void crl(T* l, T* r, int step) {
  T tmp = *l;
  for (T* i = l; i < r; i += step) *i = *(i + step);
  *(r - 1) = tmp;
}
template <class T>
void crr(T* l, T* r, int step) {
  T tmp = *(r - 1);
  for (T* i = r - 1; i > l; i -= step) *i = *(i - step);
  *l = tmp;
}
bool dbeq(double a, double b) { return fabs(a - b) < eps; }
template <class T>
void cmin(T& a, T b) {
  a = min(a, b);
}
template <class T>
void cmax(T& a, T b) {
  a = max(a, b);
}
struct node {
  int a, b, f, c, next;
} e[100 * 100 * 4];
int cnt, v[100];
void add(int a, int b, int f, int c) {
  e[cnt].a = a;
  e[cnt].b = b;
  e[cnt].f = f;
  e[cnt].c = c;
  e[cnt].next = v[a];
  v[a] = cnt++;
  e[cnt].a = b;
  e[cnt].b = a;
  e[cnt].f = 0;
  e[cnt].c = -c;
  e[cnt].next = v[b];
  v[b] = cnt++;
}
int head, tail, dis[size], q[size], pre[size], mark[size], pos[size];
bool spfa(int s, int t, int n) {
  int i, a, b;
  memset(mark, 0, sizeof(mark));
  memset(pre, -1, sizeof(pre));
  for (i = 0; i <= n; i++) dis[i] = inf;
  head = tail = 0;
  dis[s] = 0;
  q[tail++] = s;
  while (head != tail) {
    a = q[head++];
    if (head == size) head = 0;
    mark[a] = 0;
    for (i = v[a]; i != -1; i = e[i].next) {
      b = e[i].b;
      if (e[i].f > 0 && dis[b] > dis[a] + e[i].c) {
        pre[b] = a;
        pos[b] = i;
        dis[b] = dis[a] + e[i].c;
        if (!mark[b]) {
          mark[b] = 1;
          q[tail++] = b;
          if (tail == size) tail = 0;
        }
      }
    }
  }
  return pre[t] != -1 && dis[t] < inf;
}
int mcf(int s, int t, int n) {
  int flow = 0, cost = 0, mflow, i;
  while (spfa(s, t, n)) {
    mflow = inf;
    for (i = t; i != s; i = pre[i]) mflow = min(mflow, e[pos[i]].f);
    for (i = t; i != s; i = pre[i]) {
      e[pos[i]].f -= mflow;
      e[pos[i] ^ 1].f += mflow;
    }
    flow += mflow;
    cost += dis[t] * mflow;
  }
  return cost;
}
int ar[100][100];
int main() {
  int n, m, s, t;
  cin >> n >> m;
  s = 0, t = n * m + 1;
  cnt = 0, memset(v, -1, sizeof(v));
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++) {
      cin >> ar[i][j];
      int now = (i - 1) * m + j;
      if ((i + j) & 1)
        add(s, now, 1, 0);
      else
        add(now, t, 1, 0);
    }
  for (int i = 1; i < n + 1; i++)
    for (int j = 1; j < m + 1; j++) {
      int now = (i - 1) * m + j;
      if ((i + j) & 1)
        for (int k = 0; k < 4; k++) {
          int x = i + nex[0][k];
          int y = j + nex[1][k];
          int ne = (x - 1) * m + y;
          if (x >= 1 && x <= n && y >= 1 && y <= m)
            add(now, ne, 1, ar[i][j] != ar[x][y]);
        }
    }
  printf("%d\n", mcf(s, t, t));
  return 0;
}
