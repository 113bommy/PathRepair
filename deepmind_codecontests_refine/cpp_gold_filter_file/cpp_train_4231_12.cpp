#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> num(n);
  for (int i = 0; i < n; ++i) {
    int t;
    cin >> t;
    ++num[t];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) ans += max(0, num[i] - 1);
  cout << ans + 1;
  return 0;
}
