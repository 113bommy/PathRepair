#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (a < b) a = b;
}
set<int> s;
set<int>::iterator it;
vector<vector<int> > com;
int q[500500], qf, qb;
int head[999983], nxt[500500 * 2], E;
long long to[500500 * 2];
void add(int u, int v) {
  if (u > v) swap(u, v);
  long long val = (long long)u * 500500 + v;
  int id = val % 999983;
  E++;
  nxt[E] = head[id];
  to[E] = val;
  head[id] = E;
}
bool is_con(int u, int v) {
  if (u > v) swap(u, v);
  long long val = (long long)u * 500500 + v;
  int id = val % 999983;
  for (int e = head[id]; e; e = nxt[e]) {
    if (to[e] == val) return true;
  }
  return false;
}
void bfs(int u) {
  qf = qb = 0;
  q[qb++] = u;
  s.erase(u);
  com.back().push_back(u);
  while (qf < qb) {
    u = q[qf++];
    for (it = s.begin(); it != s.end();) {
      int v = *it;
      if (!is_con(u, v)) {
        s.erase(v);
        com.back().push_back(v);
        q[qb++] = v;
        it = s.lower_bound(v);
      } else
        it++;
    }
  }
}
void inline getint(int &a) {
  a = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    a = (a << 3) + (a << 1) + c - '0';
    c = getchar();
  }
}
void inline outint(int a) {
  if (a >= 10) outint(a / 10);
  putchar(a % 10 + '0');
}
int main() {
  int n, m, u, v;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    getint(u), getint(v);
    add(u, v);
  }
  for (int i = 1; i <= n; i++) s.insert(i);
  while (!s.empty()) {
    int u = *s.begin();
    com.push_back(vector<int>(0));
    bfs(u);
  }
  printf("%d\n", com.size());
  for (int i = com.size(); i--;) {
    outint(com[i].size());
    for (int j = com[i].size(); j--;) putchar(' '), outint(com[i][j]);
    puts("");
  }
  return 0;
}
