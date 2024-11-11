#include <bits/stdc++.h>
using namespace std;
struct Ping {
  int t, f;
} P[2];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    while (n--) {
      int a, t, f;
      scanf("%d %d %d", &a, &t, &f);
      P[a - 1].t += t;
      P[a - 1].f += f;
    }
    if (P[0].t >= P[0].f) printf("LIVE\n");
    if (P[0].t < P[0].f) printf("DEAD\n");
    if (P[1].t >= P[1].f) printf("LIVE\n");
    if (P[1].t < P[1].f) printf("DEAD\n");
  }
  return 0;
}
