#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  if (t[0] > 15) {
    cout << 15 << '\n';
    return 0;
  }
  for (int i = 0; i < n - 1; i++) {
    if (t[i + 1] - t[i] > 15) {
      cout << t[i] + 15 << '\n';
      return 0;
    }
  }
  cout << (90 - t[n - 1] > 15 ? t[n - 1] + 15 : 90) << '\n';
  return 0;
}
