#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l = s.size();
  long long a = 0, b = 0, c = 0, d = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] == 'o') {
      a++;
      b += c;
    }
    if (s[i] == 'v' && s[i + 1] == 'v') {
      c++;
      d += b;
    }
  }
  cout << d << endl;
  return 0;
}
