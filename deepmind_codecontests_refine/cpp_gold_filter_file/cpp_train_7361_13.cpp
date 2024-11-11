#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return a == 0 ? b : gcd(b % a, a);
}
template <class T>
string tostring(T a) {
  ostringstream os;
  os << a;
  return os.str();
}
int toint(string a) {
  istringstream is(a);
  int p;
  is >> p;
  return p;
}
long long toll(string a) {
  istringstream is(a);
  long long p;
  is >> p;
  return p;
}
int main() {
  int a, b, l;
  cin >> a >> b >> l;
  double ll = 0, r = 3.1415926535897 / 2;
  while (r - ll > 1E-12) {
    double m = (r + ll) / 2;
    double k = a * cos(m) - b * sin(m) - l * cos(2 * m);
    if (k > 0)
      r = m;
    else
      ll = m;
  }
  double d = r;
  double d1 = a * sin(d) + b * cos(d) - l * sin(d) * cos(d);
  if (max(a, b) >= l) d1 = max(d1, (double)min(a, b));
  d1 = min(d1, (double)min(a, b));
  d1 = min(d1, (double)l);
  if (d1 < 1e-11) {
    cout << "My poor head =(" << endl;
  } else {
    printf("%.9f\n", d1);
  }
}
