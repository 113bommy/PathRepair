#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a = 0;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') {
      a++;
    }
  }
  if (a <= n / 2) {
    n = 2 * a - 1;
  }
  cout << n;
}
