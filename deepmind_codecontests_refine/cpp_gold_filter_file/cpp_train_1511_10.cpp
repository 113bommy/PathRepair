#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  priority_queue<long long> q;
  int ans = 0;
  for (int i = 0, u; i < n; i++) {
    scanf("%d", &u);
    q.push(-u);
  }
  while ((int)q.size() > 1) {
    long long a = -q.top();
    q.pop();
    long long b = -q.top();
    q.pop();
    if (a == b) {
      q.push(-a - 1);
    } else {
      ans++;
      q.push(-b);
    }
  }
  ans += (int)q.size();
  printf("%d\n", ans);
}
