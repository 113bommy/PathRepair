#include <bits/stdc++.h>
using namespace std;
string s, s1;
int a[1005];
int main() {
  cin >> s;
  s1 = "";
  s1 = s[0];
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == 'a') {
      a[i] = 1 - a[i];
      a[i - 1] = 1 - a[i - 1];
    }
  }
  for (int i = 0; i < s.size(); i++) cout << a[i] << " ";
  return 0;
}
