#include <bits/stdc++.h>
using namespace std;
string s[1100];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  if (n == 1) {
    cout << 6;
    return 0;
  }
  int r = 7;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i != j) {
        int x = 0;
        for (int k = 0; k < 7; ++k)
          if (s[i][k] != s[j][k]) x++;
        r = min(r, x - 1);
      }
  int ans = r / 2;
  if (ans < 0) ans = 0;
  cout << ans;
}
