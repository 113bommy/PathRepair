#include <bits/stdc++.h>
using namespace std;
long long a = 0, b = 0, f = 0, t = 0, x[101010], s2 = 0, s3 = 0, i = 0, j = 0,
          p = 0, k = 0;
string d1, d2, d3;
int main() {
  cin >> a >> p;
  for (b = 1; b <= a; b++) {
    cin >> f;
    if (f > 5)
      s2 += 2;
    else
      s2 += 1;
  }
  cout << s2;
}
