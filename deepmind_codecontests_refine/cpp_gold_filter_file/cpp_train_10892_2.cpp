#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  string s;
  cin >> n;
  cin >> s;
  int a[3];
  a[1] = 0;
  a[2] = 0;
  for (i = 0; i < n; i++) {
    if (s[i] == 'U') {
      a[1]++;
    }
    if (s[i] == 'D') {
      a[1]--;
    }
    if (s[i] == 'L') {
      a[2]++;
    }
    if (s[i] == 'R') {
      a[2]--;
    }
  }
  cout << n - abs(a[1]) - abs(a[2]);
  return 0;
}
