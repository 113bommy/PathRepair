#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "heidi", a;
  int p = 0, i;
  cin >> a;
  for (i = 0; i < a.size(); i++) {
    if (a[i] == s[p]) {
      p++;
    }
  }
  if (p == 5)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
