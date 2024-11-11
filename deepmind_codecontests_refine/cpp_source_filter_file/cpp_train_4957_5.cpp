#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
struct node {
  int v, id;
} TM[maxn];
bool operator<(node a, node b) { return a.v < b.v; }
int n, t;
int wait[maxn];
int mx, tr[maxn];
int res;
void add(int x, int v) {
  for (int i = x; i <= n; i += i & -i) tr[i] += v;
}
int sum(int x) {
  int ans = 0;
  for (int i = x; i > 0; i -= i & -i) ans += tr[i];
  return ans;
}
int main() {
  scanf("%d%d", &n, &t);
  wait[0] = t;
  for (int i = 1; i <= n; ++i) {
    mx = max(mx, i);
    wait[i] = wait[0] - i;
    if (wait[i] == 0) break;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &TM[i].v);
    TM[i].id = i;
    TM[i].v -= i;
  }
  sort(TM + 1, TM + n + 1);
  int i = mx, j = 1;
  while (i >= 1 && j <= n) {
    while (j <= n && TM[j].v < wait[i]) {
      add(TM[j].id, 1);
      j++;
    }
    res = max(res, sum(i));
    --i;
  }
  printf("%d\n", res);
  return 0;
}
