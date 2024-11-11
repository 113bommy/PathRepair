#include <bits/stdc++.h>
using namespace std;
int n, K;
const int B = 60;
long long a[100005], maxi;
int f[64][100005], sum1[100005], sum0[100005];
long long read() {
  char c = getchar();
  long long x = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
  return x;
}
bool comp(long long a, long long b) { return a % (1 << K) < b % (1 << K); }
void csort(int k) {
  K = k + 1;
  sort(a + 1, a + n + 1, comp);
}
void init(int k) {
  for (int i = 1; i <= n; ++i) {
    sum0[i] = sum0[i - 1] + !(a[i] >> k & 1);
    sum1[i] = sum1[i - 1] + (a[i] >> k & 1);
  }
}
int main() {
  n = (int)read();
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    maxi = max(maxi, a[i]);
  }
  for (int i = 1; i <= n; ++i) a[i] = maxi - a[i];
  memset(f, 0x3f, sizeof(f));
  f[0][0] = 0;
  for (int i = 0; i < B; ++i) {
    if (i != 0) csort(i - 1);
    init(i);
    for (int j = 0; j <= n; ++j) {
      int l = sum1[n] - sum1[n - j], v = sum1[n - j] + sum0[n] - sum0[n - j];
      f[i + 1][l] = min(f[i + 1][l], f[i][j] + v);
      l = n - sum0[n - j];
      v = sum0[n - j] + sum1[n] - sum1[n - j];
      f[i + 1][l] = min(f[i + 1][l], f[i][j] + v);
    }
  }
  printf("%d\n", f[B][0]);
}
