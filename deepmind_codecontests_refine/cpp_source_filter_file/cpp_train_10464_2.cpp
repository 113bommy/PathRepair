#include <bits/stdc++.h>
using namespace std;
const int N = 200200;
const int M = 1e9 + 7;
int n;
int a[N];
int bp(int a, int b) {
  int r = 1;
  while (b > 0) {
    if (b % 2 == 1) r = 1LL * r * a % M;
    a = 1LL * a * a % M;
    b /= 2;
  }
  return r;
}
int main() {
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    ++a[x];
  }
  int k = 1, r = 1;
  for (int i = 0; i < N; ++i) {
    int p = 1, pr = r;
    for (int j = 0; j < a[i]; ++j) {
      p = 1LL * p * i % M;
      r = 1LL * r * pr % M * bp(p, k) % M;
    }
    k = 1LL * k * (a[i] + 1) % M;
  }
  printf("%d\n", r);
  return 0;
}
