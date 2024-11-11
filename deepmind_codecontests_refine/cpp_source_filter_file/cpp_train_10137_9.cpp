#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n <= 3) cout << s;
  if (n == 4) cout << s[0] << s[1] << "-" << s[2] << s[3];
  if ((n > 4) && (n % 2 == 0)) {
    for (int i = 0; i < n - 2; i++)
      if (i % 2 == 0) cout << s[i] << s[i + 1] << "-";
    cout << s[n - 2] << s[n - 1];
  }
  if ((n > 4) && (n % 2 != 0)) {
    for (int i = 0; i < n - 5; i++)
      if (n % 3 == 0) cout << s[i] << s[i + 1] << "-";
    cout << s[n - 5] << s[n - 4] << s[n - 3] << "-" << s[n - 2] << s[n - 1];
  }
  return 0;
}
