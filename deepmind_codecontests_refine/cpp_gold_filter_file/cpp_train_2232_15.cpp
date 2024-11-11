#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[4], i, b, sum = 0, l;
  string s;
  for (i = 0; i < 4; i++) {
    cin >> a[i];
  }
  cin >> s;
  l = s.length();
  for (i = 0; i < l; i++) {
    sum += a[s.at(i) - '0' - 1];
  }
  cout << sum;
  return 0;
}
