#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c;
  cin >> a >> b >> c;
  if (a > b) swap(a, b);
  if (b >= c) {
    cout << 0;
    return 0;
  }
  if (a <= 0 && b <= 0) {
    cout << -1;
    return 0;
  }
  long long int t = 0;
  if (a < 0) {
    long long int dif = (b - a) / b - 1;
    t += dif;
    a += b * dif;
  }
  while (b < c) {
    long long int k = a + b;
    a = b;
    b = k;
    t++;
  }
  cout << t;
  return 0;
}
