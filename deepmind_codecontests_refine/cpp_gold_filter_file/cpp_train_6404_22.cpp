#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1;
  cin >> s2;
  long l = s1.size();
  for (long i = 0; i < l; i++) {
    if (s1[i] == s2[i])
      s2[i] = '0';
    else
      s2[i] = '1';
  }
  cout << s2;
  return 0;
}
