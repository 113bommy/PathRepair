#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char s[105];
  cin >> s;
  bool flag = false;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n / 5; j++) {
      int k = i;
      int count = 0;
      while (k < n) {
        if (s[k] == '*') {
          k += j;
          count++;
          continue;
        } else
          break;
      }
      if (count >= 5) {
        flag = true;
        break;
      }
    }
  }
  if (flag)
    cout << "yes" << endl;
  else
    cout << "no" << endl;
  return 0;
}
