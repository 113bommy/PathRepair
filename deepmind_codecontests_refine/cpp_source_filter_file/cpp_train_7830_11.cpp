#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string second;
  cin >> second;
  int l = 0;
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (second[i] == ')') {
      r++;
    } else
      l++;
  }
  if (l != r) {
    cout << "-1";
    return 0;
  }
  r = 0;
  int cur = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (second[i] == ')') {
      r++;
      if (r == 1) {
        cur = i;
      }
    } else {
      r--;
      if (r == 0) {
        ans += i - cur + 1;
        cur = -1;
      }
    }
  }
  if (cur != -1) ans += (n - cur);
  cout << ans;
  return 0;
}
