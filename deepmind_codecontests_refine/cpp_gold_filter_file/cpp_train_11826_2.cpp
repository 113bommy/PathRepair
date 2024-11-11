#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
int ans = 3e9 + 1, ansnum = 0;
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i < n; i++) {
    int now = a[i + 1] - a[i];
    if (now == ans) {
      ansnum++;
    }
    if (now < ans) {
      ans = now;
      ansnum = 1;
    }
  }
  cout << ans << " " << ansnum;
  return 0;
}
