#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c;
  cin >> n >> c;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = INT_MIN;
  for (int i = 1; i < n; i++) {
    ans = max(ans, a[i - 1] - a[i] - c);
  }
  cout << ans << endl;
}
