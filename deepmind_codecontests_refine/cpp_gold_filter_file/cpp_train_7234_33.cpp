#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int a[MAXN], l[MAXN], r[MAXN], dp[MAXN];
stack<int> sta;
int main() {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    a[0] = 0;
    a[n + 1] = 0;
    while (!sta.empty()) sta.pop();
    for (int i = 1; i <= n; i++) {
      while (!sta.empty() && sta.top() >= a[i]) sta.pop();
      if (sta.empty())
        l[i] = a[i];
      else
        l[i] = sta.top() + 1;
      sta.push(l[i]);
    }
    while (!sta.empty()) sta.pop();
    for (int i = n; i >= 1; i--) {
      while (!sta.empty() && sta.top() >= a[i]) sta.pop();
      if (sta.empty())
        r[i] = a[i];
      else
        r[i] = sta.top() + 1;
      sta.push(r[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int tmp = min(i, min(n - i + 1, min(l[i], r[i])));
      ans = max(ans, tmp);
    }
    cout << ans << endl;
  }
  return 0;
}
