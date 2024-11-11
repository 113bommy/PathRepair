#include <bits/stdc++.h>
void prob10A() {
  int n, p1, p2, p3, t1, t2, range[100][100];
  int i, j, res = 0;
  scanf("%d %d %d %d %d %d", &n, &p1, &p2, &p3, &t1, &t2);
  for (i = 0; i < n; i++)
    for (j = 0; j < 2; j++) {
      scanf("%d", &range[i][j]);
    }
  for (i = 0; i < n; i++) {
    res = res + (range[i][1] - range[i][0]) * p1;
  }
  if (i > 1) {
    for (i = 0; i < n - 1; i++) {
      long int temp = 0;
      int inres = 0;
      temp = range[i + 1][0] - range[i][1];
      if (temp < t1)
        inres = inres + p1 * temp;
      else if (temp >= t1 && temp < t2 + t1)
        inres = inres + p1 * t1 + (temp - t1) * p2;
      else
        inres = inres + p1 * t1 + (t2)*p2 + (temp - t1 - t2) * p3;
      res += inres;
    }
  }
  printf("%d", res);
}
int main() {
  prob10A();
  return 0;
}
