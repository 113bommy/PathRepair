#include <bits/stdc++.h>
inline void read(int &x) { scanf("%d", &x); }
inline void read(long long &x) { scanf("%I64d", &x); }
inline void read(double &x) { scanf("%lf", &x); }
inline void read(long double &x) {
  double tmp;
  read(tmp);
  x = tmp;
}
template <class T>
inline void read(T *a, int n) {
  for (int i = (0); i < (n); ++i) read(a[i]);
}
inline void write(int x) { printf("%d", x); }
inline void write(long long x) { printf("%I64d", x); }
inline void write(double x) { printf("%.10lf", x); }
inline void write(long double x) { printf("%.10lf", (double)x); }
template <class T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
template <class T>
inline void writeln(T *a, int n) {
  for (int i = (0); i < (n); ++i) write(a[i]);
  putchar('\n');
}
template <class T>
inline void writelnln(T *a, int n) {
  for (int i = (0); i < (n); ++i) writeln(a[i]);
}
int n, m, deg[24];
bool av[24];
std::vector<int> adj[24];
inline bool less(int x, int y) {
  return deg[x] > deg[y] || (deg[x] == deg[y] && x < y);
}
inline void dfs(int c, int l) {
  if (l) {
    for (__typeof(adj[c].begin()) i = adj[c].begin(); i != adj[c].end(); ++i)
      if (av[*i]) {
        av[*i] = 0;
        dfs(*i, l - 1);
        av[*i] = 1;
        break;
      }
  } else {
    printf("Yes\n");
    exit(0);
  }
}
int main() {
  memset(deg, 0, sizeof(deg));
  read(n);
  read(m);
  while (m--) {
    int s, t;
    read(s);
    read(t);
    if (s == t) continue;
    bool can = true;
    for (__typeof(adj[s].begin()) i = adj[s].begin(); i != adj[s].end(); ++i)
      if (*i == t) {
        can = false;
        break;
      }
    if (!can) continue;
    ++deg[s];
    ++deg[t];
    adj[s].push_back(t);
    adj[t].push_back(s);
  }
  for (int i = (1); i <= (n); ++i)
    std::sort(adj[i].begin(), adj[i].end(), less);
  memset(av, 1, sizeof(av));
  for (int i = (1); i <= (n); ++i) {
    av[i] = 0;
    dfs(i, n - 1);
    av[i] = 1;
  }
  printf("No\n");
  return 0;
}
