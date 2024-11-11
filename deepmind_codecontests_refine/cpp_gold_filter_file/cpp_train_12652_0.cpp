#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int mxx = 4e6 + 5;
int main() {
  int a, ta, b, tb, h, m;
  scanf("%d%d%d%d", &a, &ta, &b, &tb);
  scanf("%d:%d", &h, &m);
  int s1 = 0, s2 = 0;
  int t = h * 60 + m - 5 * 60;
  int tt = t + ta;
  for (int i = 0; i <= tt; ++i) {
    if (s1 > 0 && (i - s2) % tb == 0 && i <= t) s1--, s2 += b;
    if (i % b == 0 && i != tt && i <= 1139) s1++;
  }
  printf("%d\n", s1);
  return 0;
}
