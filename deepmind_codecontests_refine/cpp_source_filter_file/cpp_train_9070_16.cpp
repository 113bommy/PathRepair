#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> a >> b >> c >> d;
  if (a > c)
    cout << (b + d + 2) * (max(a, c) + 2) - (a - c) * d - (a * b + c * d);
  else if (a < c)
    cout << (b + d + 2) * (max(a, c) + 2) - (c - a) * b - (a * b + c * d);
  else {
    cout << (max(a, c) + 2) * (b + d + 2) - a * b + c * d;
  }
  return 0;
}
