#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, i;
  string second;
  cin >> n;
  cin >> second;
  if (n % 2) {
    cout << 0;
    return 0;
  }
  int max_neg = 0, sum = 0, ans = 0;
  for (i = 0; i < n; i++) {
    sum += (second[i] == '(' ? 1 : -1);
    max_neg = min(max_neg, sum);
  }
  if (sum == 2) {
    if (max_neg == 0) {
      sum = 0;
      int max_ind = 0;
      for (i = 0; i < n; i++) {
        sum += (second[i] == '(' ? 1 : -1);
        if (sum == 0) max_ind = i;
      }
      for (i = max_ind + 1; i < n; i++) ans += (second[i] == '(');
    }
  } else if (sum == -2) {
    if (max_neg >= -2) {
      sum = 0;
      for (i = 0; i < n; i++) {
        sum += (second[i] == '(' ? 1 : -1);
        if (second[i] == ')') ++ans;
        if (sum < 0) break;
      }
    }
  }
  cout << ans;
}
