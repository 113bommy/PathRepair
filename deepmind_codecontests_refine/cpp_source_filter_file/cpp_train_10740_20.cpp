#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const long long M = 1e16;
const int N = 2e5 + 100;
void work1(int n, int m) {
  if (n > 3 * m + 1) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for (int i = 1; i <= n * 2 + 1; i++) {
    printf("%d 2\n", i);
  }
  n -= (m + 1);
  int part = min(n, m);
  for (int i = 1; i <= part; i++) {
    printf("%d 1\n", i * 2);
  }
  if (m < n) {
    n -= m;
    for (int i = 1; i <= n; i++) {
      printf("%d 3\n", i * 2);
    }
  }
  return;
}
void work2(int n, int m) {
  if (m > 3 * n + 1) {
    printf("NO\n");
    return;
  }
  printf("YES\n");
  for (int i = 1; i <= n * 2 + 1; i++) {
    printf("%d 3\n", i);
  }
  m -= (n + 1);
  int part = min(n, m);
  for (int i = 1; i <= part; i++) {
    printf("%d 2\n", i * 2);
  }
  if (m > n) {
    m -= n;
    for (int i = 1; i <= m; i++) {
      printf("%d 4\n", i * 2);
    }
  }
  return;
}
void work3(int n, int m) {
  printf("YES\n");
  for (int i = 1; i <= n * 2; i++) {
    printf("%d 1\n", i);
  }
  return;
}
int main() {
  int num;
  scanf("%d", &num);
  while (num--) {
    int n, m;
    scanf("%d%d", &n, &m);
    if (n > m) {
      work1(n, m);
    } else if (n < m) {
      work2(n, m);
    } else {
      work3(n, m);
    }
  }
  return 0;
}
