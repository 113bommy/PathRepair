#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int now = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    now = i;
    while (now + 1 < n && a[now] * 2 >= a[now + 1]) now++;
    ans = max(ans, now - i + 1);
    i = now;
  }
  cout << ans << endl;
  return 0;
}
