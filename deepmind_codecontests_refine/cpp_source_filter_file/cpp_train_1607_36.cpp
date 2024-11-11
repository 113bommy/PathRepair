#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  int d, e, f;
  cin >> a >> b >> c;
  cin >> d >> e >> f;
  int res = (a == d) + (b == e) + (c == f);
  if (res >= 2) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
