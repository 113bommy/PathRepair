#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  long long p1 = (3 * a) / 10;
  long long p2 = a - ((a * c) / (250));
  long long p3 = (3 * b) / 10;
  long long p4 = b - ((b * d) / (250));
  long long m = max(p2, p1);
  long long m1 = max(p3, p4);
  if (m > m1)
    cout << "Misha";
  else if (m < m1)
    cout << "Vasya";
  else
    cout << "Tie";
}
