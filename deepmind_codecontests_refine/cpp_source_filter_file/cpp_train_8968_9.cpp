#include <bits/stdc++.h>
using namespace std;
int pre[1000001];
int n;
string s;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin >> s;
  n = (int)(s.size());
  for (int i = 1; i < n; i++) {
    if (s[i] == 'v' && s[i - 1] == 'v') {
      pre[i]++;
    }
    pre[i] += pre[i - 1];
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      ans += pre[i] * (pre[n - 1] - pre[i]);
    }
  }
  cout << ans << '\n';
  return 0;
}
