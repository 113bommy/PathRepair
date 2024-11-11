#include <bits/stdc++.h>
using namespace std;
int n, i, j;
int main() {
  ios::sync_with_stdio(0), cout.tie(0);
  cin >> n;
  ;
  while (n--) {
    int num;
    cin >> num;
    string s;
    cin >> s;
    if (num < 11) {
      cout << "NO" << endl;
      continue;
    }
    bool ok = false;
    for (i = 0; i < num - 10; i++) {
      if (s[i] == '8') {
        ok = true;
        break;
      }
    }
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
