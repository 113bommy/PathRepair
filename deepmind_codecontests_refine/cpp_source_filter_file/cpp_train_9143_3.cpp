#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(min(c, d) - max(a, b), 0) << endl;
  return 0;
}
