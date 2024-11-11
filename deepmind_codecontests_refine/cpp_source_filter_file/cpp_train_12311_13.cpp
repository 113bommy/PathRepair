#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, c;
    cin >> a >> b >> c;
    long long c1 = -1, c2 = -1;
    if (a < c) c1 = 1;
    if (c < b * a) c2 = b;
    cout << c1 << " " << c2;
  }
}
