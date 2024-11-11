#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  priority_queue<int> q;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    ans += x / (2 * k);
    x %= 2 * k;
    q.push(x);
  }
  while (!q.empty()) {
    ans++;
    int a = q.top();
    q.pop();
    if (a > k) a -= k, q.push(a);
    if (q.empty()) break;
    a = q.top();
    q.pop();
    if (a > k) a -= k, q.push(a);
  }
  cout << ans << endl;
}
