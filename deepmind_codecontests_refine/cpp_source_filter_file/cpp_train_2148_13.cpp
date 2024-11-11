#include <bits/stdc++.h>
using namespace std;
long long n, i, j, arr[300000], a, mn, ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a;
    arr[a] = i;
  }
  mn = 1000000;
  for (i = 1; i <= 200000; i++) {
    if (arr[i] < mn && arr[i] != 0) {
      mn = arr[i];
      ans = i;
    }
  }
  cout << ans << '\n';
  return 0;
}
