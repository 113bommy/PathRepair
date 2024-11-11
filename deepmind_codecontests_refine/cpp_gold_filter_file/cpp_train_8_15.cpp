#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int e8 = 0, oth = 0;
  for (int i = 0; i < n; i++)
    if (s[i] == '8')
      e8++;
    else
      oth++;
  if (n <= 10)
    cout << 0 << endl;
  else if (e8 == n)
    cout << n / 11 << endl;
  else if ((oth / 10) >= e8)
    cout << e8 << endl;
  else {
    for (int i = e8; i >= 1; i--)
      if (((n - i) / 10) >= i) {
        cout << i << endl;
        break;
      }
  }
}
