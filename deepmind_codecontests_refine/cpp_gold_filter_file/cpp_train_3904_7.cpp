#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int d, d1;
  string s = "NO";
  for (int i = 0; i < c; i++) {
    cin >> d >> d1;
    if (d <= 5 || d1 <= 5 || a - d < 5 || b - d1 < 5) s = "YES";
  }
  cout << s;
  return 0;
}
