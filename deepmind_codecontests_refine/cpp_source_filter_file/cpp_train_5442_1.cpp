#include <bits/stdc++.h>
using namespace std;
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    cin >> n;
    int flag = 0;
    string s;
    cin >> s;
    if (n % 2 == 0) {
      for (int i = 1; i < n; i += 2) {
        if (s[i] % 2 == 0) {
          flag = 1;
          break;
        }
      }
    } else {
      flag = 1;
      for (int i = 0; i < n; i++) {
        if (s[i] % 2) {
          flag = 0;
          break;
        }
      }
    }
    if (flag)
      cout << "2\n";
    else
      cout << "1\n";
  }
  return 0;
}
