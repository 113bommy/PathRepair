#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 0; i < k; i++) {
    int c = 0, y = 0;
    for (int j = i + k; j < n; j += k) {
      if (a[i] != a[j])
        c++;
      else
        y++;
    }
    ans += ((y > c) ? c : y);
  }
  cout << ans << endl;
  return 0;
}
