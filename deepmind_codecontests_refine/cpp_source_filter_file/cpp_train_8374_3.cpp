#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 10, MOD = 1e9 + 7;
struct DSU {
  int fa[MAX_N], q[MAX_N];
  void init();
  pair<int, int> find(int x);
  void merge(int a, int b, int w);
} dsu;
int N, K, cnt;
int main() {
  scanf("%d%d", &N, &K);
  dsu.init();
  for (int i = 1; i < N - i + 1; i++) dsu.merge(i, N - i + 1, 0);
  for (int i = 1; i < N - i; i++) dsu.merge(N + i, 2 * N - i, 0);
  for (int i = 1; i <= K; i++) {
    int x, y;
    char c[10];
    scanf("%d%d%s", &x, &y, c + 1);
    if (y > x) swap(x, y);
    int a = (x - y) / 2, b = (x + y) / 2;
    if (x + y & 1) {
      if (!a) a = N;
      dsu.merge(a + N, b + N, c[1] == 'o' ? 0 : 1);
    } else {
      if (!a) a = 2 * N;
      dsu.merge(a, b, c[1] == 'o' ? 0 : 1);
    }
  }
  int ans = 1;
  for (int i = 1; i <= 2 * N - 1 - cnt; i++) ans = ans * 2 % MOD;
  printf("%d\n", ans);
}
void DSU::init() {
  for (int i = 1; i <= 2 * N; i++) fa[i] = i, q[i] = 0;
}
pair<int, int> DSU::find(int x) {
  if (x == fa[x]) return make_pair(x, 0);
  pair<int, int> t = find(fa[x]);
  return make_pair(fa[x] = t.first, q[x] ^= t.second);
}
void DSU::merge(int a, int b, int w) {
  pair<int, int> ta = find(a), tb = find(b);
  if (ta.first == tb.first) {
    if ((ta.second ^ tb.second) != w) {
      printf("0\n");
      exit(0);
    }
    return;
  }
  fa[ta.first] = tb.first;
  q[ta.first] = w ^ ta.second ^ tb.second;
  cnt++;
}
