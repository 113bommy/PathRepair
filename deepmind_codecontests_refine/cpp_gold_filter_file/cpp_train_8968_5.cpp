#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long a = 0, b = 0, c = 0, i;
  for (i = 0; i < s.length(); i++) {
    if (s[i] == 'o')
      b += a;
    else if (i > 0 && s[i - 1] == 'v') {
      a++;
      c += b;
    }
  }
  cout << c;
}
