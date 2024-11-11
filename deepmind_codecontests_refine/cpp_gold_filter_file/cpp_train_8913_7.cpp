#include <bits/stdc++.h>
using namespace std;
stack<int> q;
int n, x[200010], ans, sum;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) {
    if (x[i] == 1) {
      q.push(1);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (x[i] == 2 && !q.empty()) {
      q.pop();
      ans++;
    }
  }
  while (!q.empty()) {
    if (q.top() == 1) sum++, q.pop();
    if (sum == 3) ans++, sum = 0;
  }
  cout << ans;
}
