#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x[2], y[2], r[2], R[2], combien = 0, d;
  for (i = 0; i < 2; i++) {
    scanf("%d %d %d %d\n", &x[i], &y[i], &r[i], &R[i]);
  }
  d = (x[1] - x[0]) * (x[1] - x[0]) + (y[1] - y[0]) * (y[1] - y[0]);
  if (r[0] * r[0] <= d) {
    if ((R[1] + r[0]) * (R[1] + r[0]) <= d)
      combien++;
    else if (r[1] > r[0] && (r[1] - r[0]) * (r[1] - r[0]) >= d)
      combien++;
  } else {
    if (r[0] > r[1] && d <= (r[0] - R[1]) * (r[0] - R[1]))
      combien++;
    else if (r[1] > r[0] && (r[1] - r[0]) * (r[1] - r[0]) >= d)
      combien++;
  }
  if (r[1] * r[1] <= d) {
    if ((R[0] + r[1]) * (R[0] + r[1]) <= d)
      combien++;
    else if (r[0] > r[1] && (r[1] - r[0]) * (r[1] - r[0]) >= d)
      combien++;
  } else {
    if (r[1] > r[0] && d <= (r[1] - R[0]) * (r[1] - R[0]))
      combien++;
    else if (r[0] > r[1] && (r[1] - r[0]) * (r[1] - r[0]) >= d)
      combien++;
  }
  if (d <= R[0] * R[0]) {
    if (R[0] > R[1] && d <= (R[0] - R[1]) * (R[0] - R[1]))
      combien++;
    else if (r[1] > R[0] && d <= (r[1] - R[0]) * (r[1] - R[0]))
      combien++;
  } else {
    if ((R[1] + R[0]) * (R[1] + R[0]) <= d)
      combien++;
    else if (r[1] > R[0] && d <= (r[1] - R[0]) * (r[1] - R[0]))
      combien++;
  }
  if (d <= R[1] * R[1]) {
    if (R[1] > R[0] && d <= (R[0] - R[1]) * (R[0] - R[1]))
      combien++;
    else if (r[0] > R[1] && d <= (r[0] - R[1]) * (r[0] - R[1]))
      combien++;
  } else {
    if ((R[1] + R[0]) * (R[1] + R[0]) <= d)
      combien++;
    else if (r[0] > R[1] && d <= (r[0] - R[1]) * (r[0] - R[1]))
      combien++;
  }
  printf("%d\n", combien);
  return 0;
}
