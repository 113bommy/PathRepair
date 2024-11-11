#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, distance;
  scanf("%d%d", &N, &distance);
  int lan[1010] = {0};
  for (int i = 0; i < N; i++) scanf("%d", &lan[i]);
  sort(lan, lan + N);
  double sum = 1.0000000000 * (lan[0] - 0);
  double ok = sum;
  for (int n = 1; n < N; n++) {
    double mid = 1.0000000000 * (lan[n] - lan[n - 1]);
    if (mid > sum) sum = mid;
  }
  double last = 1.0000000000 * (distance - lan[N - 1]);
  if (lan[0] != 0 || lan[N - 1] != distance) {
    if (ok < last) ok = last;
  } else
    ok = 0;
  if (ok != 0 && sum / 2 < ok)
    printf("%.9f", ok);
  else
    printf("%.9f", sum / 2);
  return 0;
}
