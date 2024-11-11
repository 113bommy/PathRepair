#include <bits/stdc++.h>
using namespace std;
int numsol;
int heso[10], mul[10];
int sol[1000001];
int temp[9];
void Init() {
  int t = 1;
  for (int i = 0; i <= 9; ++i) {
    heso[i] = t + 1;
    t *= 10;
    mul[i] = heso[i] * 9;
    if (i > 0) mul[i] += mul[i - 1];
  }
}
void copyRes() {
  numsol++;
  int t = 1;
  for (int i = 0; i <= 9; ++i) {
    sol[numsol] += t * temp[i];
    t *= 10;
  }
}
void backtrack(int i, int k) {
  if (i == 0) {
    if (k < 20 && k % 2 == 0) {
      temp[i] = k / 2;
      copyRes();
    }
  } else if (k < heso[i]) {
    temp[i] = 0;
    backtrack(i - 1, k);
  } else {
    int t1 = (k - mul[i - 1] + heso[i] - 1) / heso[i], t2 = k / heso[i];
    t1 = max(t1, 0);
    t2 = min(t2, 9);
    if (t1 <= 9)
      for (int j = t1; j <= t2; ++j) {
        temp[i] = j;
        backtrack(i - 1, k - j * heso[i]);
      }
  }
  temp[i] = 0;
}
int main() {
  int n;
  scanf("%d", &n);
  Init();
  int t = -1;
  while (n >= heso[t + 1]) t++;
  if (t < 0) t = 0;
  backtrack(t, n);
  printf("%d\n", numsol);
  for (int i = 1; i <= numsol; ++i) {
    printf("%d ", sol[i]);
  }
  return 0;
}
