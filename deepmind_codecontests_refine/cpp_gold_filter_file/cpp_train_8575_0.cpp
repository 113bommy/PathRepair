#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  bool flag = 1;
  if (n == 1 && k == 1)
    cout << "a";
  else if (n - k < 0 || k == 1)
    cout << "-1";
  else if (k == 2) {
    for (int i = 0; i < n; i++) {
      if (flag)
        cout << "a";
      else
        cout << "b";
      flag = 1 - flag;
    }
  } else {
    for (int i = 0; i < n - (k - 2); i++) {
      if (flag)
        cout << "a";
      else
        cout << "b";
      flag = 1 - flag;
    }
    char ch = 'c';
    for (int i = 1; i <= k - 2; i++) {
      cout << ch;
      ch += 1;
    }
  }
  return 0;
}
