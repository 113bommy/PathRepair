#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(max(a * b, a * c), max(b * d, b * c)) << endl;
}
