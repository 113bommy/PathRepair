#include <bits/stdc++.h>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long> > pr;
long long n, a, ans;
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a;
    if (!pr.empty() && a > pr.top()) {
      ans += a - pr.top();
      pr.pop();
      pr.push(a);
      pr.push(a);
    } else
      pr.push(a);
  }
  cin >> ans;
  return 0;
}
