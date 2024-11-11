#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, sum;
  string s;
  cin >> n >> x >> y;
  cin >> s;
  for (int i = n - x; i < n - y - 1; i++) {
    if (s[i] == '1') {
      sum++;
      s[i] = '0';
    }
  }
  if (s[n - y - 1] == '0') {
    sum++;
    s[n - y - 1] = '1';
  }
  for (int i = n - y; i < n; i++) {
    if (s[i] == '1') {
      sum++;
      s[i] = '0';
    }
  }
  cout << sum << endl;
  return 0;
}
