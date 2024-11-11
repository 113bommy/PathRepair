#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double PI = acos(-1.0);
const int MAXN = 1e6 + 5;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void cp() {
  long long int a, b, x, y;
  long long int max_area = 0;
  long long int p, q;
  cin >> a >> b >> x >> y;
  long long int g = gcd(x, y);
  x /= g, y /= g;
  if (x > a || y > b) {
    cout << "0 0";
    return;
  }
  p = x, q = y;
  while (p + x <= a && q + y <= b) {
    p += x, q += y;
  }
  cout << p << " " << q;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int t;
  t = 1;
  while (t--) {
    cp();
  }
  return 0;
}
