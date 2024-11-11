#include <bits/stdc++.h>
using namespace std;
string second;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> second;
  int cur = 1;
  int n = second.size();
  if (n == 1) cout << 1, exit(0);
  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (second[i] != second[i - 1])
      cur++;
    else
      cur = 1;
    ans = max(ans, cur);
  }
  int tmp = 1;
  int i = 1;
  while (i < n && second[i] != second[i - 1]) {
    tmp++;
    i++;
  }
  i = n - 1;
  while (i > 0 && second[i] != second[i - 1]) {
    tmp++;
    i--;
  }
  if (second[0] != second[n - 1] && tmp < n) ans = max(ans, tmp + 1);
  cout << ans;
  return 0;
}
