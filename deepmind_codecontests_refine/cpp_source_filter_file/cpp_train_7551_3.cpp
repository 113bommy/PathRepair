#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void smax(T &x, T y) {
  x = max((x), (y));
}
template <class T>
inline void smin(T &x, T y) {
  x = min((x), (y));
}
inline void sc(int &x) {
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
void sc(char &x) { scanf("%c", &x); }
void sc(int &x, int &y) {
  sc(x);
  return sc(y);
}
void sc(int &x, int &y, int &z) {
  sc(x);
  sc(y);
  return sc(z);
}
const double eps = 1e-7;
int n, k;
vector<int> graph[2000005];
char str[2000005];
double ans = 0;
double A[2000005];
map<int, int> size;
int dfs(int from) {
  int ans = 1;
  for (long long i = 0; i < int((graph[from]).size()); i++) {
    ans += dfs(graph[from][i]);
  }
  size[from] = ans;
  return ans;
}
int dfs(int from, double last) {
  int total = 0;
  for (long long i = 0; i < int((graph[from]).size()); i++) {
    total += size[graph[from][i]];
  }
  for (long long i = 0; i < int((graph[from]).size()); i++) {
    A[graph[from][i]] = last + 1 + 0.5 * (total - size[graph[from][i]]);
    dfs(graph[from][i], A[graph[from][i]]);
  }
  return 0;
}
int main() {
  cout.precision(8);
  cout << fixed;
  std::ios::sync_with_stdio(false);
  sc(n);
  for (long long i = 0; i < n - 1; i++) {
    cin >> k;
    graph[k].push_back(i + 2);
  }
  dfs(1);
  A[1] = 1.0;
  dfs(1, 1.0);
  for (long long i = 0; i < n; i++) cout << A[i + 1] << " ";
  return 0;
}
