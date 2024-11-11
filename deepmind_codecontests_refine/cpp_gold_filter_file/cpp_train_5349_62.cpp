#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int main() {
  ios::sync_with_stdio(0);
  string s;
  cin >> s;
  if (s[0] >= 'a' && s[0] <= 'z') s[0] = (char)s[0] + 'A' - 'a';
  cout << s;
  return 0;
}
