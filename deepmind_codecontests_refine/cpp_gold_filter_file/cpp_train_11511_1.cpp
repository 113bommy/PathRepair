#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int n;
int ans = 300005, pos = 1;
long long tnow, wnow;
struct node {
  long long t, w;
} a[N];
priority_queue<long long, vector<long long>, greater<long long> > q;
bool cmp(node a, node b) { return a.t > b.t; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld%lld", &a[i].t, &a[i].w);
  tnow = a[1].t;
  wnow = a[1].w;
  a[1].t = 0;
  sort(a + 1, a + 1 + n, cmp);
  while (1) {
    while (pos <= n && a[pos].t > tnow) {
      q.push(a[pos].w - a[pos].t + 1);
      pos++;
    }
    ans = min(ans, (int)q.size() + 1);
    if (!q.size() || tnow < q.top()) break;
    tnow -= q.top();
    q.pop();
  }
  printf("%d\n", ans);
  return 0;
}
