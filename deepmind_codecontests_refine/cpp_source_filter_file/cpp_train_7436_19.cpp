#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, b, i, j, temp;
  cin >> n >> b;
  string s;
  cin >> s;
  temp = n / 2;
  if (b > temp) {
    for (i = b; i < n; i++) cout << "RIGHT" << endl;
    for (i = n - 1; i > 0; i--) {
      cout << "PRINT " << s[i] << endl;
      cout << "LETF" << endl;
    }
    cout << "PRINT " << s[0] << endl;
  } else {
    for (i = b; i > 1; i--) cout << "LETF" << endl;
    for (i = 0; i < n - 1; i++) {
      cout << "PRINT " << s[i] << endl;
      cout << "RIGHT" << endl;
    }
    cout << "PRINT " << s[n - 1] << endl;
  }
  return 0;
}
