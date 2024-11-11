#include <bits/stdc++.h>
using namespace std;
const long long big = 1000000000;
int main() {
  long long a, b, m;
  cin >> a >> b >> m;
  for (long long p = 0; p < min(m, a); p++) {
    int r = (big * p) % m;
    if ((m - r) % m > b) {
      printf("1 %09d", p);
      return 0;
    }
  }
  printf("2");
}
