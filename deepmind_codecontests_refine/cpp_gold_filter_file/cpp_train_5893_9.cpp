#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;
int t, n, m, x, y;
stack<int> s;
long long rg[N], rs[N], ls[N], lg[N], a[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = a[n + 1] = 0;
  for (int i = 1; i <= n + 1; i++) {
    while (!s.empty() && a[s.top()] > a[i]) {
      t = s.top();
      s.pop();
      rs[t] = i - 1;
    }
    s.push(i);
  }
  s.pop();
  for (int i = n; i >= 0; i--) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      t = s.top();
      s.pop();
      ls[t] = i + 1;
    }
    s.push(i);
  }
  s.pop();
  a[0] = a[n + 1] = INT_MAX;
  for (int i = 1; i <= n + 1; i++) {
    while (!s.empty() && a[s.top()] < a[i]) {
      t = s.top();
      s.pop();
      rg[t] = i - 1;
    }
    s.push(i);
  }
  s.pop();
  for (int i = n; i >= 0; i--) {
    while (!s.empty() && a[s.top()] <= a[i]) {
      t = s.top();
      s.pop();
      lg[t] = i + 1;
    }
    s.push(i);
  }
  s.pop();
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += 1LL * ((rg[i] - lg[i]) + (rg[i] - i) * (i - lg[i])) * a[i];
    ans -= 1LL * ((rs[i] - ls[i]) + (rs[i] - i) * (i - ls[i])) * a[i];
  }
  cout << ans;
  return 0;
}
