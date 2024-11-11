#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n;
int a, b, c, d, k, t;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
    int p1 = a / c;
    if (a % c) p1++;
    int p2 = b / d;
    if (b % d) p2++;
    if (p1 + p2 <= k)
      cout << p1 << " " << p2 << endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
