#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  while (s.back() == 63 || s.back() == 32) s.pop_back();
  int n, a;
  n = s.size();
  a = s.back();
  if (a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' || a == 'Y' ||
      a == 'a' || a == 'e' || a == 'o' || a == 'i' || a == 'u' || a == 'y')
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
