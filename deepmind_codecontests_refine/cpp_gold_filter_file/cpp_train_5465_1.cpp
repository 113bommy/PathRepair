#include <bits/stdc++.h>
using namespace std;
const double Pi = acos(-1.0);
const int INF = 1 << 29;
int T, S, q;
int main(int argc, char** argv) {
  scanf("%d%d%d", &T, &S, &q);
  int d = S;
  int r = 0;
  int ans = 1;
  while (d < T) {
    d += q - 1;
    r += q;
    if (d >= T) {
      break;
    }
    if (r >= d) {
      r -= d;
      ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
