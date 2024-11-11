#include <bits/stdc++.h>
using namespace std;
string s;
int main() {
  cin >> s;
  int n = s.size();
  int x = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u' || s[i] == '0' || s[i] == '2' || s[i] == '4' ||
        s[i] == '6' || s[i] == '8')
      x++;
  }
  cout << x << endl;
  return 0;
}
