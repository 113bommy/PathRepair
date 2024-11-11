#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 7;
const long long linf = 1ll << 60;
const double dinf = 1e10;
inline long long read() {
  bool f = 0;
  long long x = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (f) x = -x;
  return x;
}
inline void scf(int &x) {
  bool f = 0;
  x = 0;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') {
    f = 1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  if (f) x = -x;
  return;
}
void scf(int &x, int &y) {
  scf(x);
  return scf(y);
}
void scf(int &x, int &y, int &z) {
  scf(x);
  scf(y);
  return scf(z);
}
const int N = 2e5 + 100;
int n, cnt;
int a[N], b[N], c[N], d[N];
int dst[N], prevv[N];
int q[N];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    heap[N];
map<int, int> hashx;
inline void modify(int i, const pair<int, int> &x) {
  for (; i <= cnt; i += (i & (-i))) heap[i].push(x);
  return;
}
inline vector<int> query(int i, const int &y) {
  vector<int> ret;
  ret.clear();
  for (; i; i ^= (i & (-i))) {
    while ((int)heap[i].size()) {
      pair<int, int> tmp = heap[i].top();
      if (tmp.first > y) break;
      ret.push_back(tmp.second);
      heap[i].pop();
    }
  }
  return ret;
}
inline void out(int u = n) {
  if (prevv[u]) out(prevv[u]), putchar(' ');
  printf("%d", u);
  return;
}
int main() {
  scf(n);
  for (int i = (1); i <= (n); i++) {
    scf(a[i], b[i]);
    scf(c[i], d[i]);
    hashx[a[i]];
    hashx[c[i]];
  }
  if (hashx.find(0) == hashx.end()) {
    puts("-1");
    return 0;
  }
  for (auto it = hashx.begin(); it != hashx.end(); it++) it->second = (++cnt);
  memset(dst, -1, sizeof(dst));
  int fnt = 0, rar = 0;
  for (int i = (1); i <= (n); i++) {
    a[i] = hashx[a[i]], c[i] = hashx[c[i]];
    if (a[i] == 1 && !b[i])
      dst[i] = 0, q[rar++] = i;
    else
      modify(a[i], make_pair(b[i], i));
  }
  hashx.clear();
  while (fnt != rar) {
    int u = q[fnt++];
    vector<int> tmp = query(c[u], d[u]);
    for (auto v : tmp)
      if (dst[v] < 0) {
        dst[v] = dst[u] + 1;
        prevv[v] = u;
        q[rar++] = v;
      }
  }
  if (dst[n] < 0) {
    puts("-1");
    return 0;
  }
  printf("%d\n", dst[n] + 1);
  out();
  putchar('\n');
  return 0;
}
