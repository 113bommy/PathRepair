#include <bits/stdc++.h>
using namespace std;
int main() {
  int ar[1010] = {0}, n, i, j = 1;
  char ch;
  cin >> n;
  int count = 0;
  for (i = 1; i <= n; i++) {
    cin >> ch;
    if (ch == '*') {
      ar[i] = 1;
    }
  }
  count = 0;
  int flag = 0;
  int ans, a;
  for (i = 1; i <= n; i++) {
    if (ar[i]) {
      a = i;
      ans = 1;
      while (ans < n) {
        count = 0;
        for (int k = a;; k += ans) {
          if (ar[k]) {
            count++;
            if (count == 4) {
              cout << "yes\n";
              return 0;
            }
          } else
            break;
        }
        ans++;
      }
    }
  }
  cout << "no\n";
  return 0;
}
