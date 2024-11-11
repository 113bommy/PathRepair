#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool uin(T& a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
const int N = 501000;
const int M = 36;
int n;
int p[N];
int h[N];
double d[N][M];
double old[M];
void up(int a, int b, int h) {
  for (int j = min(M - 2, h); j >= 0; --j) {
    old[j + 1] = d[a][j + 1];
    d[a][j + 1] /= (1 + old[j]);
    d[a][j + 1] *= (1 + d[b][j]);
  }
  old[0] = d[a][0];
}
void add(int v) {
  p[n] = v;
  ++n;
  v = n - 1;
  d[v][0] = 0.0;
  for (int j = 0; j < (int)(M); ++j) old[j] = 1.0;
  int hh = 0;
  while (p[v] >= 0 && hh <= M) {
    int u = p[v];
    up(u, v, hh);
    ++hh;
    v = u;
  }
}
double get(int v) {
  double ans = 0;
  for (int j = 0; j < (int)(M - 1); ++j) ans += j * (d[v][j + 1] - d[v][j]);
  return ans;
}
void solve() {
  n = 1;
  for (int v = 0; v < (int)(N); ++v)
    for (int j = 0; j < (int)(M); ++j) d[v][j] = 1.0;
  d[0][0] = 0.0;
  int q;
  p[0] = -1;
  scanf("%d", &q);
  for (int _ = 0; _ < (int)(q); ++_) {
    int t, v;
    scanf("%d%d", &t, &v);
    --v;
    if (t == 1)
      add(v);
    else
      printf("%.8f\n", (double)get(v));
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed;
  cout.precision(15);
  cerr << fixed;
  cerr.precision(15);
  solve();
  return 0;
}
