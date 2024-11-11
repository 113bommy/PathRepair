#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int a, b, c, k = 0;
  int t = s.size();
  for (int i = 0; i < t; i++) {
    if (s[i] == 'a') k++;
  }
  if (k > t)
    cout << t;
  else {
    cout << 2 * k - 1;
  }
  return 0;
}
