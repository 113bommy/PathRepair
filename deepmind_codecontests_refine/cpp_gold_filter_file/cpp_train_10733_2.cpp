#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void read(T &x) {
  bool b = 0;
  char c;
  while (!isdigit(c = getchar()) && c != '-')
    ;
  if (c == '-') c = getchar(), b = 1;
  x = c - 48;
  while (isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - 48;
  if (b) x = -x;
}
template <typename T>
inline void wrip(T x) {
  if (x > 9) wrip(x / 10);
  putchar(x % 10 + 48);
}
template <typename T>
inline void write(T x) {
  if (x < 0) putchar('-'), x = -x;
  wrip(x);
  putchar(' ');
}
template <typename T>
inline void writeln(T x) {
  if (x < 0) putchar('-'), x = -x;
  wrip(x);
  putchar('\n');
}
inline char readch() {
  char c;
  do c = getchar();
  while (c == '\n');
  return c;
}
inline void reads(string &s) {
  char c;
  s = "";
  do c = getchar();
  while (c == ' ' || c == '\n');
  do {
    s += c;
    c = getchar();
  } while (c != ' ' && c != '\n');
}
const double pi = acos(-1);
const int inf = 1e9;
const int N = 2e5 + 11;
int n, k1, k2, choose;
int has[N], ok[N], b[N];
vector<int> ke[N];
void Dfs(int u, int p) {
  has[u] = (u == choose);
  for (auto v : ke[u]) {
    if (v == p) continue;
    Dfs(v, u);
    if (!ok[v]) has[u] |= has[v];
  }
}
int Ask(int type, int u) {
  cout << (type ? "B " : "A ") << u << '\n';
  fflush(stdout);
  cin >> u;
  return u;
}
void Ans(int u) {
  cout << "C " << u << '\n';
  fflush(stdout);
}
int main() {
  int ntest;
  read(ntest);
  while (ntest--) {
    read(n);
    for (int i = 1, u, v; i < n; i++) {
      read(u);
      read(v);
      ke[u].push_back(v);
      ke[v].push_back(u);
    }
    read(k1);
    for (int i = 1, u; i <= k1; i++) {
      read(u);
      ok[u] = 1;
    }
    read(k2);
    for (int i = 1; i <= k2; i++) read(b[i]);
    choose = Ask(1, b[1]);
    if (ok[choose]) {
      Ans(choose);
      goto line;
    }
    int root, subtree;
    for (int i = 1; i <= n; i++)
      if (ok[i]) root = i;
    Dfs(root, 0);
    for (int i = 1; i <= n; i++)
      if (ok[i] && has[i]) subtree = i;
    choose = Ask(0, subtree);
    for (int i = 1; i <= k2; i++)
      if (b[i] == choose) {
        Ans(subtree);
        goto line;
      }
    Ans(-1);
  line:;
    for (int i = 1; i <= n; i++) ok[i] = 0, ke[i].clear();
  }
}
