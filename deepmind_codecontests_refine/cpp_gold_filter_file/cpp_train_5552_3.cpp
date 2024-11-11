#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  pair<int, int> ar[n];
  int ans = 0;
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    cin >> ar[i].second >> ar[i].first;
  }
  sort(ar, ar + n);
  for (int i = n - 1; i >= 0; i--) {
    if (cnt > 0) {
      cnt = cnt - 1 + ar[i].first;
      ans += ar[i].second;
    } else
      break;
  }
  cout << ans;
  return 0;
}
