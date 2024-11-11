#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int ans[100010], a[100010], d[100010], n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    a[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    d[i] = i - a[x];
  }
  for (int i = 1; i <= n; i++) ans[i] = n + 1;
  while (!pq.empty()) pq.pop();
  for (int i = 1; i <= n; i++)
    if (d[i] >= 0) pq.push(-d[i]);
  for (int i = 1; i <= n; i++) {
    ans[i] = -pq.top() - i + 1;
    pq.push(-d[i] - n);
    while (!pq.empty() && -pq.top() - i + 1 == 0) pq.pop();
  }
  while (!pq.empty()) pq.pop();
  for (int i = 1; i <= n; i++)
    if (d[i] < 0) pq.push(d[i]);
  for (int i = 1, j = 1; j <= n; j++) {
    if (!pq.empty()) ans[i] = min(ans[i], -pq.top() - j + 1);
    i = (i + n - 2) % n + 1;
    pq.push(d[i] - n);
    while (!pq.empty() && pq.top() + j == 0) pq.pop();
  }
  for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
  return 0;
}
