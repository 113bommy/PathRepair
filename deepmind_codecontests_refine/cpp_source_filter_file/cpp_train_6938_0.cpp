#include <bits/stdc++.h>
using namespace std;
long long finder(long long N, long long M) {
  return (N * N) - ((N / M) * (N / M));
}
int tr;
int binserM(int L, int R, int tmp, int P) {
  int mid = (L + R) / 2;
  if (L > R) return tmp;
  long long now = finder(P, mid);
  if (now <= tr) {
    return binserM(mid + 1, R, mid, P);
  } else if (now > tr) {
    return binserM(L, mid - 1, tmp, P);
  }
}
int main() {
  int tc;
  scanf("%d", &tc);
  for (int ntc = 0; ntc < tc; ntc++) {
    scanf("%d", &tr);
    bool check = 0;
    int outN = 0, outM = 0;
    for (int a = 1; a <= 33000; a++) {
      int now = binserM(1, a, 0, a);
      if (now == 0) continue;
      if (tr == finder(a, now)) {
        check = 1;
        outN = a;
        outM = now;
        break;
      }
    }
    if (check) {
      printf("%d %d", outN, outM);
    } else {
      printf("-1");
    }
    printf("\n");
  }
  return 0;
}
