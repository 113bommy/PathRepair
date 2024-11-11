#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int k = s[0];
  if (k >= 97 || k <= 122) {
    k -= 32;
  }
  s[0] = k;
  cout << s;
  return 0;
}
