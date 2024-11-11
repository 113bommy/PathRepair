#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, s, p, k, m, x, y, ans;
  string a, b, c;
  cin >> a;
  s = 0;
  for (int i = 0; i < a.size(); i++) {
    m = a[i];
    if (m < 95)
      s++;
    else
      s--;
    b += tolower(a[i]);
    c += toupper(a[i]);
  }
  if (s > 0)
    cout << c << endl;
  else
    cout << b << endl;
  return 0;
}
