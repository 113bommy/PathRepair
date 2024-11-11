#include <bits/stdc++.h>
using namespace std;
int max(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
int main() {
  int n, lim, sum1;
  cin >> n;
  int a[n], pre[n];
  vector<int> c;
  string b;
  for (int i = 0; i < n; i++) cin >> a[i];
  cin >> b;
  sum1 = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == '1') {
      c.push_back(i);
      sum1 += a[i];
    }
  }
  pre[0] = a[0];
  for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
  long long int ans = sum1;
  for (int i = 0; i < c.size(); i++) {
    if (c[i] == 0)
      ans = max(ans, sum1 - a[c[i]]);
    else if (i + 1 >= c.size())
      ans = max(ans, pre[c[i] - 1]);
    else
      ans = max(ans, sum1 - a[c[i]] + pre[c[i] - 1]);
    sum1 -= a[c[i]];
  }
  cout << ans << endl;
  return 0;
}
