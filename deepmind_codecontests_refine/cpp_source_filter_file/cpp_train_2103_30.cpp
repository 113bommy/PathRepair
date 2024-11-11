#include <bits/stdc++.h>
using namespace std;
int bugcnt;
const int maxn = 1e6 + 5;
int t;
double a, b, c, d, k;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> d >> k;
    if (ceil(a / c) + ceil(c / d) > k)
      puts("-1");
    else
      printf("%d %d\n", (int)ceil(a / c), (int)ceil(b / d));
  }
}
