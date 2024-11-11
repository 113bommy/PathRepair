#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  while (cin >> n) {
    getchar();
    string s[n + 5];
    for (int i = 0; i < n; i++) cin >> s[i];
    long long l = 0, g = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j += 3) {
        if (s[i][j] == 'O' && s[i][j + 1] == 'O') {
          s[i][j] = '+', s[i][j + 1] = '+';
          l = 1, g = 1;
          break;
        }
      }
      if (g == 1) break;
    }
    if (l == 1) {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
      }
    } else if (l == 0)
      cout << "NO" << endl;
  }
  return 0;
}
