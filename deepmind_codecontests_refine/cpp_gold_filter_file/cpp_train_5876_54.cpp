#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, d;
  cin >> s >> d;
  reverse(s.begin(), s.end());
  if (s == d)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
