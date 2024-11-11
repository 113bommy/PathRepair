#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  cin >> n >> s;
  int c1 = 0, c0 = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1')
      c1++;
    else
      c0--;
  }
  if (c1 != c0)
    cout << "1\n" << s;
  else {
    cout << "2\n";
    for (int i = 0; i < n - 1; i++) cout << s[i];
    cout << " ";
    cout << s[n - 1];
  }
  return 0;
}
