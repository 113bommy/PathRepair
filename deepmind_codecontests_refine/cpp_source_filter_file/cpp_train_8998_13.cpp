#include <bits/stdc++.h>
using namespace std;
string s;
int k;
int main() {
  cin >> s;
  if (s.size() > 1)
    k = s[s.size()] - '0' + (s[s.size() - 1] - '0') * 10;
  else
    k = s[s.size()] - '0';
  if (k % 4)
    cout << 0 << endl;
  else
    cout << 4 << endl;
}
