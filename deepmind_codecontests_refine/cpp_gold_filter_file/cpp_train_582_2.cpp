#include <bits/stdc++.h>
using namespace std;
long long n, a, ans = 0;
priority_queue<int> q;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    q.push(-a);
    q.push(-a);
    ans += a + q.top();
    q.pop();
  }
  cout << ans;
  return 0;
}
