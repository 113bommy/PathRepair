#include <bits/stdc++.h>
using namespace std;
int n, a[5000];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0, mov = a[i];
    for (int j = i; j > 1; j--) {
      if (a[j - 1] <= mov) {
        cnt++;
        mov = a[j - 1];
      } else
        break;
    }
    mov = a[i];
    for (int j = i; j < n - 1; j--) {
      if (a[j + 1] <= mov) {
        cnt++;
        mov = a[j + 1];
      } else
        break;
    }
    ans = max(ans, cnt + 1);
  }
  cout << ans << endl;
}
