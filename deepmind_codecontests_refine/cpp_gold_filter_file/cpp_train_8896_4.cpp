#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0, b = 0, c;
  char s[1002], s1[1002], s2[1002], l[10];
  cin >> n;
  cin.getline(l, n);
  cin.getline(s, n + 1);
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      s1[i] = '0';
    else
      s1[i] = '1';
    if (s[i] != s1[i]) a++;
  }
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      s2[i] = '1';
    else
      s2[i] = '0';
    if (s[i] != s2[i]) b++;
  }
  c = a < b ? a : b;
  cout << c << endl;
  return 0;
}
