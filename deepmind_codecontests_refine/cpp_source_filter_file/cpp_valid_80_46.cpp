#include <bits/stdc++.h>
using namespace std;
int T, n;
string s;
int main() {
  cin >> T;
  while (T--) {
    bool flag = 0;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
      if (flag) break;
      if (s[i - 1] == '0') {
        if ((i - 1) > n / 2)
          cout << "1 " << i << "1 " << i - 1 << endl;
        else
          cout << i << " " << n << " " << i + 1 << " " << n << endl;
        flag = 1;
      }
    }
    if (!flag) {
      if (n % 2) {
        cout << "1 " << n / 2 << " " << n / 2 + 1 << " " << n - 1 << endl;
      } else {
        cout << "1 " << n / 2 << " " << n / 2 + 1 << " " << n << endl;
      }
    }
  }
  return 0;
}
