#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e6 + 10;
const int inf = (int)2e9;
int A[N], B[N];
int main() {
  int n, k1, k2;
  scanf("%d %d %d", &n, &k1, &k2);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &B[i]);
  priority_queue<int> pq;
  for (int i = 1; i <= n; i++) {
    pq.push(abs(A[i] - B[i]));
  }
  for (int i = 1; i <= k1 + k2; i++) {
    int top = pq.top();
    pq.pop();
    pq.push(abs(top - 1));
  }
  long long ans = 0;
  while (!pq.empty()) {
    int top = pq.top();
    pq.pop();
    ans += (top * top);
  }
  printf("%lld\n", ans);
  return 0;
}
