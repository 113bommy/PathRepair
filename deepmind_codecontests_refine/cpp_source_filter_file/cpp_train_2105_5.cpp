#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, countl = 0, countr = 0;
  cin >> n;
  string s;
  cin >> s;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == 'L') countl++;
    if (s[i] == 'R') countr;
  }
  cout << (countl + countr + 1);
  return 0;
}
