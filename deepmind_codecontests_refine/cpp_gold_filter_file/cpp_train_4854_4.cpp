#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > qu;
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (qu.empty())
      qu.push(x);
    else {
      int o = qu.top();
      if (o > x)
        qu.push(x);
      else {
        ans += x - o;
        qu.pop();
        qu.push(x);
        qu.push(x);
      }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
