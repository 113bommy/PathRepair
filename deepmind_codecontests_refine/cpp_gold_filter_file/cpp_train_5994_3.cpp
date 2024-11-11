#include <bits/stdc++.h>
using namespace std;
string s, a;
int main() {
  cin >> s;
  a = s;
  s.append(s);
  cout << s.find(a, 1) << endl;
  return 0;
}
