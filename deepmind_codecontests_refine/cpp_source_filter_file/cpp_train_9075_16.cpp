#include <bits/stdc++.h>
using namespace std;
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }
int main() {
  string s;
  cin >> s;
  int four = 0, seven = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '4') four++;
    if (s[i] == '7') seven++;
  }
  if (four == 0 && seven == 0) cout << "-1" << endl;
  if (four >= seven)
    cout << "4" << endl;
  else
    cout << "7" << endl;
  return 0;
}
