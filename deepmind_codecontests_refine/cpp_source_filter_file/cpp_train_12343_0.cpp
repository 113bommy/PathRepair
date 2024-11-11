#include <bits/stdc++.h>
using namespace std;
long long x[4];
void solve(int tc) {
  for (int i = 0; i < 4; i++) scanf("%lld", x + i);
  if (x[0] == 0 && x[1] == 0 && x[2] == 0 && x[3] == 0) {
    puts("0");
    return;
  }
  if (x[0] == 1 && x[1] == 0 && x[2] == 0 && x[3] == 0) {
    puts("00");
    return;
  }
  if (x[0] == 0 && x[1] == 0 && x[2] == 0 && x[3] == 1) {
    puts("11");
    return;
  }
  if (x[0] == 0 && x[1] == 1 && x[2] == 0 && x[3] == 0) {
    puts("01");
    return;
  }
  if (x[0] == 0 && x[1] == 0 && x[2] == 1 && x[3] == 0) {
    puts("10");
    return;
  }
  if (x[0] == 0 && x[1] == 0 && x[2] == 0) {
    long long m = sqrt(x[3] + x[3]) + 1;
    if (m * (m - 1) != x[3] + x[3]) {
      puts("Impossible");
      return;
    } else {
      for (int i = 0; i < m; i++) printf("1");
    }
    return;
  }
  if (x[3] == 0 && x[1] == 0 && x[2] == 0) {
    long long m = sqrt(x[0] + x[0]) + 1;
    if (m * (m - 1) != x[0] + x[0]) {
      puts("Impossible");
      return;
    } else {
      for (int i = 0; i < m; i++) printf("0");
    }
    return;
  }
  long long n;
  n = sqrt(x[0] + x[0]) + 1;
  int ok = 1;
  if (n * (n - 1) != x[0] + x[0]) ok = 0;
  long long m = sqrt(x[3] + x[3]) + 1;
  if (m * (m - 1) != x[3] + x[3]) ok = 0;
  if (ok == 0) {
    puts("Impossible");
    return;
  }
  if (x[0] + x[1] + x[2] + x[3] != (n + m) * (n + m - 1) / 2) {
    puts("Impossible");
    return;
  }
  for (int i = 0; i < x[2] / n; i++) printf("1");
  long long u = x[2] - n * (x[2] / n);
  if (u != 0) {
    for (int i = 0; i < u; i++) printf("0");
    printf("1");
    for (int i = 0; i < n - u; i++) printf("0");
    for (int i = 0; i < m - 1 - x[2] / n; i++) printf("1");
  } else {
    for (int i = 0; i < n; i++) printf("0");
    for (int i = 0; i < m - x[2] / n; i++) printf("1");
  }
}
int main() {
  int Tc = 1;
  for (int tc = 1; tc <= Tc; tc++) {
    solve(tc);
  }
  return 0;
}
