#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c = 0, p = 0, i, l;
  string a;
  cin >> n;
  cin >> a;
  for (i = 0; i < sizeof(a); i++) {
    if (a[i] == 'x')
      c++;
    else
      c = 0;
    if (c >= 3) p++;
  }
  cout << p;
}
