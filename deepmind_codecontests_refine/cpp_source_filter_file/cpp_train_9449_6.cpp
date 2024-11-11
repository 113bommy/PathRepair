#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(max(a * c, b * d), max(a * d, b * c)) << endl;
}
