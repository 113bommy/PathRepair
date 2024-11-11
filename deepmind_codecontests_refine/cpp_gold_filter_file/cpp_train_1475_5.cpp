#include <bits/stdc++.h>
using namespace std;
int a[1234567];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int ans, cnt;
  ans = cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > cnt) {
      ans++;
      cnt++;
    }
  }
  cout << ans;
}
