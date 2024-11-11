#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:200000000")
using namespace std;
template <typename T>
inline T Abs(T x) {
  return (x >= 0) ? x : -x;
}
template <typename T>
inline T sqr(T x) {
  return x * x;
}
template <typename T>
string toStr(T x) {
  stringstream st;
  st << x;
  string s;
  st >> s;
  return s;
}
inline int nextInt() {
  int x;
  if (scanf("%d", &x) != 1) throw;
  return x;
}
inline long long nextInt64() {
  long long x;
  if (scanf("%I64d", &x) != 1) throw;
  return x;
}
inline double nextDouble() {
  double x;
  if (scanf("%lf", &x) != 1) throw;
  return x;
}
const int INF = (int)1E9;
const long long INF64 = (long long)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
const int MAXN = 100100;
vector<int> g[MAXN];
long double ans = 0;
int n;
void DFS(int v, int prev, int h) {
  ans += 1.0 / h;
  for (int i = 0; i < (int)(g[v].size()); i++) {
    int u = g[v][i];
    if (u != prev) DFS(u, v, h + 1);
  }
}
int main() {
  n = nextInt();
  for (int i = 0; i < (int)(n - 1); i++) {
    int v = nextInt() - 1;
    int u = nextInt() - 1;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  DFS(0, 0, 1);
  cout.precision(10);
  cout << fixed << ans << endl;
  return 0;
}
