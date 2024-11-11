#include <bits/stdc++.h>
using namespace std;
int n;
int k;
int con[2][42];
int flag[1 << 20];
int __builtin_pop_count(int num) {
  int r = 0;
  while (num) {
    if (num & 1) {
      r++;
    }
    num >>= 1;
  }
  return r;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int a;
      scanf("%d", &a);
      con[j / 20][i] |= (a << (j % 20));
    }
  }
  int mx = 0;
  int N = n;
  n = min(N, 20);
  for (int i = 1; i < (1 << n); i++) {
    int sum = i;
    int c = (1 << n) - 1;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        sum &= ((1 << j) | con[0][j]);
      }
    }
    if (sum != i) {
      continue;
    }
    int b = __builtin_pop_count(i);
    mx = max(mx, b);
    for (int j = 0; j < n; j++) {
      if ((sum >> j) & 1) {
        c &= con[1][j];
      }
    }
    flag[c] = max(flag[c], b);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      if (!((j >> i) & 1)) {
        flag[j] = max(flag[j], flag[j ^ (1 << i)]);
      }
    }
  }
  for (int j = 0; j < (1 << n); j++) {
    if (flag[j] != 0) {
      flag[j] += __builtin_pop_count(j);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      if (((j >> i) & 1)) {
        flag[j] = max(flag[j], flag[j ^ (1 << i)]);
      }
    }
  }
  n = max(0, N - 20);
  for (int i = 1; i < (1 << n); i++) {
    int sum = i;
    for (int j = 0; j < n; j++) {
      if ((i >> j) & 1) {
        sum &= ((1 << j) | con[1][j + 20]);
      }
    }
    if (sum != i) {
      continue;
    }
    mx = max(mx, __builtin_pop_count(sum));
    mx = max(mx, flag[sum]);
  }
  double R = k;
  R /= (double)(mx);
  R *= R;
  R *= (double)((mx * (mx - 1)) / 2);
  printf("%.16f\n", R);
  return 0;
}
