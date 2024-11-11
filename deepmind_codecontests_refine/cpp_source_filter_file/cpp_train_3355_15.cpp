#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int tr[N * 2];
int minpos[N], maxpos[N];
int a[N];
int pos[2 * N];
int n, m;
int bound;
int lowbit(int x) { return x & (-x); }
void add(int pos, int d) {
  for (int i = pos; i <= bound; i += lowbit(i)) tr[i] += d;
}
int query(int x) {
  int res = 0;
  for (int i = bound; i > 0; i -= lowbit(i)) res += tr[i];
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  bound = n + m;
  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    minpos[i] = i, maxpos[i] = i;
    add(i + m, 1);
    pos[i] = i + m;
  }
  for (int i = 1; i <= m; ++i) {
    int now = a[i];
    minpos[now] = 1;
    maxpos[now] = max(maxpos[now], query(pos[now]));
    add(pos[now], -1);
    pos[now] = m - i + 1;
    add(pos[now], 1);
  }
  for (int i = 1; i <= n; ++i) maxpos[i] = max(maxpos[i], query(pos[i]));
  for (int i = 1; i <= n; ++i) printf("%d %d\n", minpos[i], maxpos[i]);
  return 0;
}
