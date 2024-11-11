#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0;
  string s;
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a') c++;
  }
  if (c <= n / 2) {
    cout << c * 2 - 1;
  } else
    cout << n;
  return 0;
}
