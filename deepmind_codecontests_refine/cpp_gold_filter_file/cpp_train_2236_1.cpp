#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long> > q;
int n, m, i, x, y;
long long z;
int main() {
  cin >> n >> m;
  for (i = 0; i < m; i++) q.push(0);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &x, &y);
    z = max(q.top(), 1LL * x) + y;
    q.push(z);
    q.pop();
    printf("%I64d\n", z);
  }
  return 0;
}
