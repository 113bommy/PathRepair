#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string k;
    cin >> k;
    int count = 1;
    int ans = 0;
    if (k[n - 1] == k[0]) {
      int x = 1;
      int i = 1;
      int y = 1;
      while (k[i] == k[0]) {
        i++;
        x++;
      }
      int j = i;
      i = n - 2;
      if (x == n) {
        if (n % 3) {
          ans = n / 3 + 1;
        } else {
          ans = n / 3;
        }
        cout << ans << endl;
        return 0;
      }
      while (k[i] == k[n - 1]) {
        y++;
        i--;
      }
      for (; j <= i; j++) {
        if (k[j] == k[j - 1]) {
          count++;
        } else {
          ans += count / 3;
          count = 1;
        }
      }
      ans += count / 3;
      ans += (x + y) / 3;
      cout << ans << endl;
    } else {
      for (int j = 1; j <= n - 1; j++) {
        if (k[j] == k[j - 1]) {
          count++;
        } else {
          ans += count / 3;
          count = 1;
        }
      }
      ans += count / 3;
      cout << ans << endl;
    }
  }
}
