#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
int main() {
  long long c, c1, c2, v1, v2;
  while (cin >> c >> v1 >> v2 >> c1 >> c2) {
    long long cc = sqrt(c);
    long long Max = 0;
    for (long long i = 1; i <= cc; i++) {
      if (i * c1 <= c) Max = max(Max, i * v1 + ((c - i * c1) / c2) * v2);
      if (i * c2 <= c) Max = max(Max, i * v2 + ((c - i * c2) / c1) * v1);
    }
    cout << Max << endl;
  }
}
