#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc, n;
  string s;
  cin >> tc;
  while (tc--) {
    cin >> n >> s;
    int size = s.length(), i = 0;
    bool flag = false;
    for (i = 0; i < size / 2; ++i) {
      int first = s[i];
      int second = s[size - i - 1];
      if (abs((first - second)) > 0 && (abs(abs(first - second) - 2) > 0)) {
        flag = true;
        break;
      }
    }
    if (!flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
