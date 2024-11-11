#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
map<int, int> m;
int dp[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  int b;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  dp[0] = 1;
  m[a[0]] = 1;
  int mx = 1;
  for (int i = 1; i < n; i++) {
    m[a[i]] = m[a[i] - 1] + 1;
    mx = max(mx, m[a[i]]);
  }
  cout << mx << endl;
  int j = 0, pos = 0;
  for (int i = n - 1; i > -1; i--) {
    if (m[a[i]] == mx) {
      j = a[i];
      pos = i;
      break;
    }
  }
  stack<int> ans;
  ans.push(pos);
  for (int i = pos - 1; i > -1; i--) {
    if (a[i] == j - 1) {
      ans.push(i);
      j--;
    }
  }
  while (!ans.empty()) {
    cout << ans.top() + 1 << " ";
    ans.pop();
  }
  cout << "\n";
  return 0;
}
