#include <bits/stdc++.h>
using namespace std;
const int MAX = 25;
int n;
int l[6][6], h[6][6], a[6][6];
int out;
bool ok;
int cCost;
int ba[6];
void go(int cur, int to, int cost) {
  if (cur == n - 1) {
    ok = true;
    cCost = max(cCost, cost);
    return;
  }
  if (to >= n) {
    if (ba[cur]) return;
    go(cur + 1, cur + 2, cost);
    return;
  }
  if (ba[cur] < l[cur][to]) return;
  int MX = min(ba[cur], h[cur][to]);
  for (int add = l[cur][to]; add <= MX; add++) {
    if (add) cost += a[cur][to];
    ba[cur] -= add;
    ba[to] += add;
    cost += add * add;
    go(cur, to + 1, cost);
    cost -= add * add;
    ba[cur] += add;
    ba[to] -= add;
    if (add) cost -= a[cur][to];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < ((n - 1) * n) / 2; i++) {
    int s, f;
    scanf("%d %d", &s, &f);
    s--;
    f--;
    scanf("%d", &l[s][f]);
    scanf("%d", &h[s][f]);
    scanf("%d", &a[s][f]);
  }
  for (out = 0; out < MAX; out++) {
    ok = false;
    cCost = -1;
    ba[0] = out;
    for (int i = 1; i < n; i++) ba[i] = 0;
    go(0, 1, 0);
    if (ok) {
      printf("%d %d\n", out, cCost);
      return 0;
    }
  }
  printf("-1 -1\n");
  return 0;
}
