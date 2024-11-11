#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
  int n, b, d, cnt = 0, ans = 0;
  cin >> n >> b >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (cnt >= d) {
      cnt = 0;
      ans++;
    }
    if (a[i] > b) {
      i++;
    } else
      cnt += a[i];
  }
  if (cnt >= d) {
    cnt = 0;
    ans++;
  }
  cout << ans;
  return 0;
}
