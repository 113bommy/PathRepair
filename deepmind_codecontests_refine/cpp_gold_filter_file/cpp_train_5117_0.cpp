#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t = "QRUOPSDGCBJ";
  cin >> s;
  if (s.find_first_of(t) == -1 || s.find_first_not_of(t) == -1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
