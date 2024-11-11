#include <bits/stdc++.h>
using namespace std;
const int MXN = 200010, inf = ~0U >> 1;
int N;
int fa[MXN], isr[MXN] = {}, ring[MXN], rn = 0, treen = 0, root = -1;
int step = 0;
void init() {
  scanf("%d\n", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", fa + i);
  for (int i = 1; i <= N; ++i) {
    int x, y;
    for (x = i; !isr[x]; x = fa[x]) isr[x] = i;
    if (isr[x] == i) {
      ring[++rn] = x;
    }
    for (y = i; y != x; y = fa[y]) isr[y] = -1;
  }
  for (int i = 1; i <= N; ++i) {
    if (fa[i] == i) {
      treen++;
      if (root == -1) root = i;
    }
  }
  if (root == -1) {
    int x = ring[rn];
    fa[x] = x;
    root = x;
    --rn;
    ++step;
  }
  for (int i = 1; i <= rn; ++i) {
    int x = ring[i];
    if (fa[x] != root) {
      fa[x] = root;
      ++step;
    }
  }
}
namespace solve {
void solve() {
  cout << step << endl;
  for (int i = 1; i <= N; ++i) printf("%d%c", fa[i], i < N ? ' ' : '\n');
}
}  // namespace solve
int main() {
  {
    init();
    solve::solve();
  }
  return 0;
}
