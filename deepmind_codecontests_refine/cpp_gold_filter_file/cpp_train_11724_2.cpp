#include <bits/stdc++.h>
using namespace std;
struct flight {
  int index, cost;
  bool operator<(const flight &f) const { return cost < f.cost; }
} c[300010];
priority_queue<flight> q;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &c[i].cost);
    c[i].index = i;
    if (i <= k) {
      q.push(c[i]);
    }
  }
  long long cnt = 0;
  for (int i = k + 1; i <= n + k; i++) {
    if (i <= n) {
      q.push(c[i]);
    }
    flight now = q.top();
    q.pop();
    cnt += (long long)(i - now.index) * now.cost;
    c[now.index].index = i;
  }
  printf("%I64d\n", cnt);
  printf("%d", c[1].index);
  for (int i = 2; i <= n; i++) {
    printf(" %d", c[i].index);
  }
  return 0;
}
