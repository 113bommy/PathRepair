#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  cout << max(a, max(b, max(c / 2, max(d / 7, e / 4)))) << endl;
  return 0;
}
