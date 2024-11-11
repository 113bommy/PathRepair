#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * (1e5) + 10, inf = 2147483647;
long long ans;
int n, lastR, lastB, lastP, mxR, mxB;
int change(char ch);
int main() {
  int x;
  char c;
  scanf("%d", &n);
  lastR = lastB = lastP = -inf;
  mxR = mxB = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %c\n", &x, &c);
    if (c == 'R' || c == 'P') {
      if (lastR != -inf) ans += x - lastR, mxR = max(mxR, x - lastR);
      lastR = x;
    }
    if (c == 'B' || c == 'P') {
      if (lastB != -inf) ans += x - lastB, mxB = max(mxB, x - lastB);
      lastB = x;
    }
    if (c == 'P') {
      if (lastP != -inf) ans += min(0, x - lastP - mxR - mxB);
      lastP = x;
      mxR = mxB = 0;
    }
  }
  printf("%I64d\n", ans);
}
