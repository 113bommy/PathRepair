#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, j, c, i;
  cin >> k;
  int ans[50];
  for (i = 0; i < k; i++) {
    c = 0;
    cin >> n;
    string str;
    cin >> str;
    for (j = 0; j < (n / 2); j++) {
      int a = str[j];
      int b = str[n - 1 - j];
      if ((a - b) != 0 && (a - b) != 2 && (a - b) != -2) {
        c++;
      }
    }
    if (c == 0) {
      ans[i] = 1;
    } else {
      ans[i] = 0;
    }
  }
  for (; i < 50; i++) {
    ans[i] = 2;
  }
  for (i = 0; i < k; i++) {
    if (ans[i] == 1) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << "\n";
  }
  return 0;
}
