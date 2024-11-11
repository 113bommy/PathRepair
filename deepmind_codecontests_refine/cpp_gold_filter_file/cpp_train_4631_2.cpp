#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  string s;
  long long i, l;
  cin >> s;
  l = s.size() - 1;
  for (i = 0; i <= l; i++) {
    if (s[i] == '5') s[i] = '4';
    if (s[i] == '6') s[i] = '3';
    if (s[i] == '7') s[i] = '2';
    if (s[i] == '8') s[i] = '1';
    if (s[i] == '9' && i > 0) s[i] = '0';
  }
  cout << s;
  return 0;
}
