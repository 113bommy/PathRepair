#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[30];
  int n;
  string s;
  while (cin >> n >> s) {
    memset(a, 0, sizeof(a));
    if (n == 1)
      cout << "Yes" << endl;
    else {
      for (int i = 0; i < s.length(); i++) {
        int p = s[i] - 96;
        a[p]++;
      }
      int cnt = 0;
      for (int i = 0; i < 26; i++) {
        if (a[i] == 1) cnt++;
      }
      if (cnt == n)
        cout << "No" << endl;
      else
        cout << "Yes" << endl;
    }
  }
  return 0;
}
