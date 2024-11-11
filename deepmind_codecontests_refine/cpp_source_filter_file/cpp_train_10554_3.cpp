#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T& x) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (x = 0; c > 32; c = getchar()) x = x * 10 + c - '0';
  if (fu) x = -x;
};
inline char getc() {
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  return c;
}
const int N = 100100;
int n, i, j, k, l, p;
long long sz[N], ans;
int edge, e[N << 1], b[N << 1], fir[N];
void add(int x, int y) {
  e[++edge] = y;
  b[edge] = fir[x];
  fir[x] = edge;
}
void dfs(int i, int f) {
  long long t = 0;
  sz[i] = 1;
  for (int k = fir[i]; k; k = b[k])
    if (e[k] != f) {
      dfs(e[k], i);
      t += sz[i] * sz[e[k]];
      sz[i] += sz[e[k]];
    }
  ans -= t * (t + 2 * (n - sz[i]) * sz[i]);
}
int main() {
  int x, y;
  read(n);
  for (i = 1; i <= n - 1; i++) read(x), read(y), add(x, y), add(y, x);
  ans = n * (n - 1) / 2;
  ans *= ans;
  dfs(1, 0);
  cout << ans << endl;
  scanf("\n");
  return 0;
}
