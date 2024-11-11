#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int ans = 0, ct0 = 0, ct1;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == 1) {
      ct1 = 0;
      for (int j = i; j <= n; j++) {
        if (arr[i] == 1) {
          ct1 += 1;
        }
      }
      ans = max(ans, ct0 + ct1);
    } else {
      ct0 += 1;
      ans = max(ans, ct0);
    }
  }
  cout << ans << endl;
}
