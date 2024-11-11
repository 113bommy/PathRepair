#include <bits/stdc++.h>
using namespace std;
int n, p;
long long ans;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p);
    if (!q.empty() && q.top() < p) {
      ans += (p - q.top());
      q.pop();
      q.push(p);
    }
    q.push(p);
  }
  printf("%lld\n", ans);
}
