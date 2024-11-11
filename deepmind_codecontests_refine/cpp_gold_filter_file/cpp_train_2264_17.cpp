#include <bits/stdc++.h>
using namespace std;
int n;
int a[201];
long long ans;
int main() {
  cin >> n;
  int temp;
  for (int i = 0; i < 2 * n; i++) cin >> a[i];
  for (int i = 0; i <= 2 * n - 2; i += 2) {
    if (a[i + 1] == a[i]) continue;
    for (int j = i + 2; j < 2 * n; j++) {
      if (a[j] == a[i]) {
        for (int k = j; k >= i + 2; k--) {
          temp = a[k - 1];
          a[k - 1] = a[k];
          a[k] = temp;
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
