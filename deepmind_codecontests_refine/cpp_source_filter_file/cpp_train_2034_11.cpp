#include <bits/stdc++.h>
using namespace std;
int main() {
  string a = "127", b = "32767", c = "2147483647", d = "9223372036854775807";
  string s;
  cin >> s;
  int l = s.size();
  if (l < a.size() || (l == a.size() && s <= a))
    cout << "byte" << endl;
  else if (l <= b.size() || (l == b.size() && s <= b))
    cout << "short" << endl;
  else if (l <= c.size() || (l == c.size() && s <= c))
    cout << "int" << endl;
  else if (l <= d.size() || (l == d.size() && s <= d))
    cout << "long" << endl;
  else
    cout << "BigInteger" << endl;
  return 0;
}
