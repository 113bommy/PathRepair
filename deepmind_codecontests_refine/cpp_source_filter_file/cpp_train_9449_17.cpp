#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(max(a * d, a * c), max(b * c, b * d)) << endl;
}
