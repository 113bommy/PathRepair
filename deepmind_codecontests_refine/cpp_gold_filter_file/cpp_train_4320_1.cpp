#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], ans[N], l[N], r[N];
int n;
void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
}
int main() {
  ios_base::sync_with_stdio(false);
  input();
  fill(l + 1, l + 1 + n, 0);
  fill(r + 1, r + 1 + n, n + 1);
  memset(ans, 0, sizeof ans);
  stack<int> s;
  for (int i = 1; i <= n; i++) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    if (!s.empty()) l[i] = s.top();
    s.push(i);
  }
  while (!s.empty()) {
    s.pop();
  }
  for (int i = n; i >= 1; i--) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    if (!s.empty()) r[i] = s.top();
    s.push(i);
  }
  for (int i = 1; i <= n; i++) {
    int len = r[i] - l[i] - 1;
    ans[len] = max(ans[len], a[i]);
  }
  for (int i = n; i >= 1; i--) {
    ans[i] = max(ans[i], ans[i + 1]);
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
