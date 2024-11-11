#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c = 0;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == '0' && s[i + 1] == '1') c++;
  }
  if (s[n - 1] == '0') c++;
  if (a > b)
    cout << b * c;
  else if (c)
    cout << b + a * (c - 1);
  else
    cout << 0;
  return 0;
}
