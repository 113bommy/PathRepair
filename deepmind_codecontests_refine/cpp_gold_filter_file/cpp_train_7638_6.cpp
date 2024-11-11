#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, d;
  cin >> n >> m >> d;
  int arr[n * m];
  for (int i = 0; i < n * m; i++) cin >> arr[i];
  int ans = INT_MAX;
  int cnt;
  for (int i = 1; i <= 10000; i++) {
    cnt = 0;
    int move = 0;
    for (int j = 0; j < n * m; j++) {
      if (abs(arr[j] - i) % d == 0) {
        cnt++;
        move += (abs(arr[j] - i) / d);
      }
    }
    if (cnt == n * m) ans = min(ans, move);
  }
  if (ans == INT_MAX)
    cout << "-1" << endl;
  else
    cout << ans << endl;
}
