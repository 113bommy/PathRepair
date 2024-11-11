#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 10;
int n, a[N], ans[N];
priority_queue<int> q;
int main() {
  scanf("%d", &n);
  for (auto i = 1; i <= n; i++) scanf("%d", a + i);
  for (auto i = 1; i <= n; i++) q.push(a[i] + i);
  ans[n + 1] = inf;
  for (auto i = n; i >= 1; i--) {
    ans[i] = q.top() - i;
    q.pop();
    if (ans[i] > ans[i + 1]) {
      printf(":(");
      return 0;
    }
  }
  for (auto i = 1; i <= n; i++) printf("%d ", ans[i]);
}
