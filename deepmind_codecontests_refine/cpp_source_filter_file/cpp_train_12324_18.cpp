#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x = 0;
  string s;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> s;
    if (s[1] == '+')
      x++;
    else
      x--;
    cout << x << endl;
  }
  return 0;
}
