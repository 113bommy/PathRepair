#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, cnt, mx = 0;
  cin >> n;
  string a, ans;
  cin >> a;
  for (int i = 1; i < n; i++) {
    cnt = 0;
    for (int j = 1; j < n; j++) {
      if (a[j] == a[i] && a[j - 1] == a[i - 1]) {
        cnt++;
      }
    }
    if (cnt > mx) {
      mx = cnt;
      ans = a[i - 1];
      ans += a[i];
    }
  }
  cout << ans;
  return 0;
}
