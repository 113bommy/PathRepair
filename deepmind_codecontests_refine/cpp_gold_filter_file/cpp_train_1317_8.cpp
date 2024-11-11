#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int num = 1;
  int evenn = (n / 2);
  if (n <= 3) {
    cout << n;
    return 0;
  } else {
    for (int i = evenn; i > 0; i--) {
      bool good = true;
      for (int g = 0; g < i; g++) {
        if (s[g] != s[g + i]) {
          good = false;
          break;
        }
      }
      if (good) {
        cout << n - i + 1 << endl;
        return 0;
      }
    }
  }
  cout << n << endl;
  return 0;
}
