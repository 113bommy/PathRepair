#include <bits/stdc++.h>
using namespace std;
int main() {
  string s = "heidi", a;
  int p = 0;
  cin >> a;
  for (int i; i <= a.size(); i++) {
    if (a[i] == s[p]) {
      p++;
    }
  }
  if (p == 4)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
