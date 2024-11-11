#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, b, a;
  cin >> s >> b;
  for (int i = s.length() - 1; i >= 0; i--) {
    a += s[i];
  }
  if (a == b)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
