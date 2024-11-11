#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s[10005], s1[10005], a, b;
  cin >> a >> b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> s1[i];
  }
  for (int i = 0; i < n; i++) {
    cout << a << " " << b << endl;
    if (a == s[i])
      a = s1[i];
    else
      b = s1[i];
  }
  cout << a << " " << b << endl;
  return 0;
}
