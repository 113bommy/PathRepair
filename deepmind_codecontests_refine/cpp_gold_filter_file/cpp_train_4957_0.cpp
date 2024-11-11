#include <bits/stdc++.h>
using namespace std;
int n, t;
priority_queue<int> q;
int main() {
  scanf("%d%d", &n, &t);
  int ans = 0;
  for (int(i) = (1); (i) <= (int)(min(n, t - 1)); (i)++) {
    int x;
    scanf("%d", &x);
    while (!q.empty() && t - i <= q.top()) q.pop();
    if (x < t) q.push(x - i);
    ans = max(ans, (int)q.size());
  }
  printf("%d\n", ans);
  return 0;
}
