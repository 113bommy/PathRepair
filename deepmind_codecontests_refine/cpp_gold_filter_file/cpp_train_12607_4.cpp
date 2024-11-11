#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
int n;
long long A[M], X[M], B[M], t, now;
int main() {
  scanf("%d%I64d", &n, &t);
  for (int i = 1; i <= n; i++) scanf("%I64d", &A[i]);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &X[i]);
    if (X[i] < X[i - 1] || X[i] < i) {
      puts("No");
      return 0;
    }
  }
  for (int i = 1; i < n; i++) {
    B[i] = A[i + 1] + t - (X[i] != X[i + 1]);
  }
  B[n] = A[n] + t + 1;
  now = n;
  for (int i = n; i >= 1; i--) {
    if (B[i] <= B[i - 1]) {
      puts("No");
      return 0;
    }
    if (now != X[i]) {
      puts("No");
      return 0;
    }
    if (B[i - 1] - A[i] < t) now = i - 1;
  }
  puts("Yes");
  for (int i = 1; i <= n; i++) printf("%I64d ", B[i]);
  return 0;
}
