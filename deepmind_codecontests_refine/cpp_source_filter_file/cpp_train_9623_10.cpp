#include <bits/stdc++.h>
using namespace std;
int f[1000005];
int main() {
  int N;
  int p = 0;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int x;
    scanf("%d", &x);
    p ^= x;
  }
  f[0] = 0;
  for (int i = 0; i <= N; ++i) f[i] = f[i - 1] ^ i;
  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    int a = (N / i) & 1, b = N % i;
    if (a)
      ans ^= f[i] ^ f[b];
    else
      ans ^= f[b];
  }
  printf("%d\n", ans ^ p);
  return 0;
}
