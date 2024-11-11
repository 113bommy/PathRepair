#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const long long inf = 1LL << 30;
const double eps = 1e-9;
const long long mod = 1e9 + 7;
const int N = 2000020;
int a[N];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  long long pos1 = 0, pos2 = 0;
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      pos1 += x;
      pos2 += x;
    } else {
      if (abs(pos1) & 1)
        pos1--;
      else
        pos1++;
      if (abs(pos2) & 1)
        pos2++;
      else
        pos2--;
    }
  }
  for (int x = 1; x <= n; x++) {
    int posx = x;
    if (x & 1)
      posx += pos1;
    else
      posx += pos2;
    posx = (posx % n + n) % n;
    if (!posx) posx = n;
    a[posx] = x;
  }
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}
