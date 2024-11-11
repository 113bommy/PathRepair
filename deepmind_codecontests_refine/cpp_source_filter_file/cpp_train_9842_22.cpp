#include <bits/stdc++.h>
using namespace std;
int main() {
  long d, h, v, e;
  float s, t;
  double PI = 3.14159;
  cin >> d;
  cin >> h;
  cin >> v;
  cin >> e;
  t = 4 * v - PI * d * d * e;
  s = (PI * d * d * h) / (4 * v - PI * d * d * e);
  if (t < 0) {
    cout << "NO";
  } else {
    cout << "YES"
         << "\n";
    cout << s;
  }
}
