#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int x, n, k;
  while (cin >> k) {
    int num[10] = {0};
    char ch;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        cin >> ch;
        if (ch >= 49 && ch <= 57) num[ch - 48]++;
      }
    }
    int mx = 0;
    for (int i = 0; i <= 9; i++) {
      if (mx < num[i]) mx = num[i];
    }
    if (mx <= 2 * k)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
