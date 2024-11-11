#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, nr;
int main() {
  cin >> a >> b >> c >> d;
  nr = abs(a * d - b * c);
  double dr = max(max(abs(a + b + c + d), abs(a - b + c - d)),
                  max(abs(a - b - c - d), abs(a + b - c - d)));
  printf("%.9f", dr ? nr / dr : 0);
}
