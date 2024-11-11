#include <bits/stdc++.h>
using namespace std;
int s, mx;
int N, T, mxy, mn = 9999999;
int d[105];
int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &d[i]);
  }
  scanf("%d", &T);
  sort(d, d + N);
  mx = d[N - 1];
  mn = d[0];
  for (int i = mn; i <= mx; i++) {
    s = 0;
    for (int j = 0; j < N; j++) {
      if (d[j] >= i && d[j] <= i + T) s++;
    }
    mxy = max(mxy, s);
  }
  printf("%d\n", mxy);
  return 0;
}
