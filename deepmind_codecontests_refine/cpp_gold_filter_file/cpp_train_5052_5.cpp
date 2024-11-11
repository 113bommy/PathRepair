#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long> > q;
int n, b, a, t, d;
int main() {
  scanf("%d%d", &n, &b);
  long long cur = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &t, &d);
    while (!q.empty() && q.top() <= t) {
      q.pop();
    }
    if (q.size() == b + 1)
      printf("-1 ");
    else {
      if (t > cur)
        cur = t + d;
      else
        cur += d;
      q.push(cur);
      printf("%I64d ", cur);
    }
  }
}
