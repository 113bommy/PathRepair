#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, sq;
  cin >> a >> b >> c;
  sq = sqrt(a * b * c);
  cout << (sq / a + sq / b + sq / c) * 4;
  return 0;
}
