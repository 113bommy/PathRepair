#include <bits/stdc++.h>
using namespace std;
const int N = 38086176 + 100;
int d[N];
int dd(int n) {
  if (d[n] != -1) return d[n];
  if (n >= 61728) {
    if (dd(n - 61728) == 1) {
      d[n] = 1;
      return 1;
    }
  }
  if (n >= 617) {
    if (dd(n - 617) == 1) {
      d[n] = 1;
      return 1;
    }
  }
  d[n] = 0;
  return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < N; i++) {
    d[i] = -1;
  }
  d[0] = 1;
  do {
    if (n % 2 == 0) {
      if (dd((n / 2) % (38086176)) == 1) {
        printf("YES\n");
        return 0;
      }
    }
    n -= 1234567;
  } while (n >= 1234567);
  printf("NO\n");
  return 0;
}
