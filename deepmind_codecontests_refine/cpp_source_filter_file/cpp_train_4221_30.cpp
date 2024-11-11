#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  while (n) {
    s += char(n % 8 + '0');
    n /= 8;
  }
  int res = 0;
  for (int i = 0; i < (int)s.size(); i++) res += (s[i] == '0');
  cout << res << endl;
}
