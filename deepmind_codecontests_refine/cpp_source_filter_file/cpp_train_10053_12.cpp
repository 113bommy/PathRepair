#include <bits/stdc++.h>
using namespace std;
int N, A, B, d[2003], a[2003], b[2003], ab[2003];
pair<int, int> calc(int c1, int c2) {
  int ans1 = 0, ans2 = 0, rem = 0;
  for (int i = 1; i <= N; i++) {
    int add1 = a[i] - c1, add2 = b[i] - c2;
    int add3 = a[i] + b[i] - ab[i] - c1 - c2;
    if (add1 < 0 && add2 < 0 && add3 < 0)
      d[i] = d[i - 1];
    else if (add3 > add1 && add3 > add2)
      d[i] = d[i - 1] + add3, ans1++, ans2++;
    else if (add1 > add2)
      d[i] = d[i - 1] + add1, ans1++;
    else if (add2 > add1)
      d[i] = d[i - 1] + add2, ans2++;
    else
      d[i] = d[i - 1] + add1, rem++;
  }
  if (ans1 >= A) return {ans1, ans2 + rem};
  int da = min(A - ans1, rem);
  return {ans1 + da, ans2 + rem - da};
}
int main() {
  scanf("%d %d %d", &N, &A, &B);
  for (int i = 1, x, f; i <= N; i++) {
    scanf("%d.%d", &x, &f);
    a[i] = x * 1000000 + f * 1000;
  }
  for (int i = 1, x, f; i <= N; i++) {
    scanf("%d.%d", &x, &f);
    b[i] = x * 1000000 + f * 1000;
  }
  for (int i = 1; i <= N; i++) ab[i] = (a[i] / 1000) * (b[i] / 1000);
  int al = 0, ar = 1000000, am, bm, ansa = 1000001, ansb = 1000001;
  while (al <= ar) {
    am = (al + ar) / 2;
    int bl = 0, br = 1000000, tmp = 1000001;
    while (bl <= br) {
      bm = (bl + br) / 2;
      if (calc(am, bm).second <= B)
        br = bm - 1, tmp = bm;
      else
        bl = bm + 1;
    }
    if (calc(am, tmp).first <= A)
      ar = am - 1, ansa = am, ansb = tmp;
    else
      al = am + 1;
  }
  calc(ansa, ansb);
  int sum = d[N] + ansa * A + ansb * B;
  printf("%d.%06d\n", sum / 1000000, sum % 1000000);
  return 0;
}
