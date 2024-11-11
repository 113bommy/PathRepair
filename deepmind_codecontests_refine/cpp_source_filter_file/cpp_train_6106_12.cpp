#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int a[100005], b[100005];
int main() {
  int l = -1e9, r = 100000007 - 7;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  string s;
  cin >> s;
  for (int i = 1; i <= s.size(); i++) b[i] = s[i - 1] - '0';
  for (int i = 5; i <= n; i++) {
    if (b[i] == b[i - 1]) continue;
    if (b[i] == 1) {
      l = max(
          max(max(max(max(a[i], a[i - 1]), a[i - 2]), a[i - 3]), a[i - 4]) + 1,
          l);
    } else {
      r = min(
          min(min(min(min(a[i], a[i - 1]), a[i - 2]), a[i - 3]), a[i - 4]) - 1,
          r);
    }
  }
  cout << l << " " << r << endl;
  return 0;
}
