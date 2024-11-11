#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, k;
  cin >> s >> k;
  reverse(s.begin(), s.end());
  if (k == s)
    cout << "YES";
  else
    cout << "N0";
}
