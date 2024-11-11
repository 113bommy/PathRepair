#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    getchar();
    string s;
    cin >> s;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int y;
      y = s[i] - '0';
      if (i == (n - 1)) {
        ans = ans + y;
      } else {
        if (y != 0) ans = ans + y + 1;
      }
    }
    cout << ans << endl;
  }
}
