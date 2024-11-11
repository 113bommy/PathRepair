#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if ((s[s.length() - 1] - '0') % 2 == 0)
    cout << 0;
  else
    cout << 1;
}
