#include <bits/stdc++.h>
using namespace std;
long long a, b, c;
string s;
int main() {
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'o')
      b += a;
    else if (s[i - 1] == 'v')
      a++, c += b;
  }
  cout << c;
}
