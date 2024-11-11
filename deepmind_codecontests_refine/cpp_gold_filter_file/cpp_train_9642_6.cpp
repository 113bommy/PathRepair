#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, y = 0, x = 0;
  string s;
  cin >> n;
  cin >> s;
  for (int i = 0; i <= n - 2; i++) {
    for (int j = i + 1; j < n; j++) {
      if (s[i] == 'S' && s[j] == 'F') {
        y++;
        break;
      }
      if (s[i] == 'F' && s[j] == 'S') {
        x++;
        break;
      }
      break;
    }
  }
  if (y > x) {
    cout << "YES";
  } else
    cout << "NO";
}
