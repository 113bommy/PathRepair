#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int i = 0;
  while (s[i] == '.') i++;
  int j = i;
  if (s[i] == 'L') {
    while (s[j] == 'L') j++;
    cout << j << " " << i + 1;
  } else {
    while (s[j] == 'R') j++;
    if (s[j] == '.') j++;
    cout << i + 1 << " " << j;
  }
  return 0;
}
