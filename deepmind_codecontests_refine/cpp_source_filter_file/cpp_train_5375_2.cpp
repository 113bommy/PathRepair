#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  while (b) a %= b, swap(a, b);
  return a;
}
long long a, b, p, x, y;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b;
  if (a == b)
    cout << "Equal\n";
  else {
    p = a * b / gcd(a, b);
    x = p / a - 1;
    y = p / b - 1;
    if (a > b)
      x++;
    else
      y++;
    if (x > y)
      cout << "Dasha\n";
    else if (x < y)
      cout << "Mesha\n";
    else
      cout << "Equal\n";
  }
}
