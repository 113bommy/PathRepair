#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, d, arr[10001];
  cin >> n >> m >> d;
  for (int i = 1; i <= (n * m); i++) cin >> arr[i];
  int curr = arr[1] % d;
  for (int i = 2; i <= (n * m); i++) {
    if (curr != (arr[i] % d)) {
      cout << -1;
      return 0;
    }
  }
  sort(arr + 1, arr + (n * m) + 1);
  int ans = 0, mid = arr[(n * m) / 2 + 1];
  for (int i = 1; i <= (n * m); i++) {
    ans += (abs(arr[i] - mid) / d);
  }
  cout << ans;
  return 0;
}
