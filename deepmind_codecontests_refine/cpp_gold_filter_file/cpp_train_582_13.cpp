#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > h;
int main() {
  int n, x;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    h.push(x);
    h.push(x);
    ans += x - h.top();
    h.pop();
  }
  printf("%lld\n", ans);
  return 0;
}
