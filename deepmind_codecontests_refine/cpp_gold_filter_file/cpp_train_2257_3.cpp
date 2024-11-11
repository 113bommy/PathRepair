#include <bits/stdc++.h>
using namespace std;
const int N = 101;
int n, a[2 * N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cin >> n;
  for (int i = 1; i <= 2 * n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 2; i <= 2 * n; i += 2) {
    if (a[i] == a[i - 1]) continue;
    for (int j = i + 1; j <= 2 * n; j++) {
      if (a[j] == a[i - 1]) {
        for (int k = j; k > i; k--) {
          swap(a[k], a[k - 1]);
          ans++;
        }
        break;
      }
    }
  }
  cout << ans << endl;
}
