#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  long long n, m, a[105][10];
  while (scanf("%d%d", &n, &m) != EOF) {
    int temp = 1;
    for (int i = 2; i > 0; i--) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = temp;
        temp += 2;
      }
    }
    temp = 2;
    for (int i = 4; i >= 3; i--) {
      for (int j = 1; j <= n; j++) {
        a[i][j] = temp;
        temp += 2;
      }
    }
    for (int j = 1; j <= n; j++) {
      for (int i = 1; i <= 4; i++) {
        if (a[i][j] <= m) {
          printf("%d ", a[i][j]);
        }
      }
    }
    puts("");
  }
  return 0;
}
