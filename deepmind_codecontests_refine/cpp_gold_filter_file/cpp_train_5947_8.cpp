#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, flag = 0;
  string s;
  cin >> n;
  cin >> s;
  for (i = 0; i < n - 1; i++) {
    if (flag == 0 && s[i] != s[i + 1]) {
      flag = 1;
      cout << "YES" << endl;
      cout << s[i] << s[i + 1];
    }
  }
  if (flag == 0) cout << "NO";
  return 0;
}
