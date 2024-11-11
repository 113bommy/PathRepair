#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
using namespace std;
inline int F(int x) {
  if (x < 0) return -INF;
  int t = x % 4;
  if (!t)
    return x / 4;
  else if (t == 1)
    return F(x - 9) + 1;
  else if (t == 2)
    return F(x - 6) + 1;
  else
    return F(x - 15) + 2;
}
int N;
int main() {
  int x;
  scanf("%d", &N);
  while (N--) {
    scanf("%d", &x);
    x = F(x);
    if (x < 0) x = -1;
    printf("%d\n", x);
  }
}
