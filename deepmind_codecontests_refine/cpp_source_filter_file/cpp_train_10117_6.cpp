#include <bits/stdc++.h>
using namespace std;
const int M = 1000, N = 5e5;
long long Eans[M + 3][M + 3], It[N + 3];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int Itmp, Ia, Ib;
    scanf("%d%d%d", &Itmp, &Ia, &Ib);
    if (Itmp == 1) {
      It[Ia] += Ib;
      for (int j = 1; j <= M; j++) Eans[j][Ia % j] += Ib;
    } else {
      if (Ia <= M)
        printf("%lld\n", Eans[Ia][Ib]);
      else {
        long long Ans = 0;
        for (int j = Ib; j <= n; j += Ia) Ans += It[j];
        printf("%lld\n", Ans);
      }
    }
  }
  return 0;
}
