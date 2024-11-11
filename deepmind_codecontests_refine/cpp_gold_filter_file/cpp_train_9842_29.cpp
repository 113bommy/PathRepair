#include <bits/stdc++.h>
using namespace std;
int main() {
  double d, h, v, e;
  double pi = 3.14159265359;
  double s;
  cin >> d >> h >> v >> e;
  s = pi * d * d / 4;
  double t = 0;
  if (e * s >= v)
    cout << "NO";
  else {
    t = (s * h) / (v - e * s);
    cout << "YES" << endl << t;
  }
  return 0;
}
