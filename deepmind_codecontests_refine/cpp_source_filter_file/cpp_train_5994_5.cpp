#include <bits/stdc++.h>
using namespace std;
string s, a;
int main() {
  cin >> s;
  a = s;
  s.append(s);
  cout << s.find(a) << endl;
  return 0;
}
