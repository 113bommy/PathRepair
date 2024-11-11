#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  long long f = 0, p = 0;
  for (int i = 0; i < a.length(); i++) {
    string s = "";
    if (i + 5 <= a.length())
      s += a[i], s += a[i + 1], s += a[i + 2], s += a[i + 3], s += a[i + 4];
    if (s == "heavy")
      p++;
    else if (s == "metal")
      f += p;
  }
  cout << f;
  return 0;
}
