#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s[0] - 'a' > 0) s[0] = s[0] - 'a' + 'A';
  cout << s << endl;
  return 0;
}
