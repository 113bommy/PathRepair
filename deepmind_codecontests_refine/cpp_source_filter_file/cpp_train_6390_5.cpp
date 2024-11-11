#include <bits/stdc++.h>
using namespace std;
int N;
char L[100005], R[100005];
long long p2[100005], p10[100005], p11[100005], f[100005], g[100005];
long long G(long long x, int i) { return x * p10[i] % 1000000007; }
long long H(long long x, int i) { return x * p11[i] % 1000000007; }
long long F(long long x, int i) {
  x = G(x, i);
  return (f[i] + x * x % 1000000007 * (p2[i] - 1) % 1000000007 +
          (g[i] * 2 - H(4 + 7, i)) % 1000000007 * x) %
         1000000007;
}
void work() {
  p2[0] = p10[0] = 1;
  for (int i = 0; i <= N; i++) {
    p2[i + 1] = p2[i] * 2 % 1000000007, p10[i + 1] = p10[i] * 10 % 1000000007,
           p11[i + 1] = (p11[i] * 10 + 1) % 1000000007;
    f[i + 1] = (F(4, i) + F(7, i) +
                ((G(4, i) + H(7, i)) % 1000000007) *
                    ((G(7, i) + H(4, i)) % 1000000007)) %
               1000000007;
    g[i + 1] = (G(4 + 7, i) * p2[i] + g[i] * 2) % 1000000007;
  }
}
long long calc(char* s) {
  long long x = 0, y, res = 0;
  for (int i = 1, j; i <= N; i++)
    if (s[i] == '4')
      (x = x * 10 + 4) % 1000000007;
    else {
      y = (x * 10 + 4) % 1000000007, (x = x * 10 + 7) % 1000000007, j = N - i;
      (res += F(y, j) + ((G(y, j) + H(7, j)) % 1000000007) *
                            ((G(x, j) + H(4, j)) % 1000000007)) %= 1000000007;
    }
  return res;
}
void doit() {
  scanf("%s%s", L + 1, R + 1), N = strlen(L + 1);
  work();
  printf("%d\n", (calc(R) - calc(L) + 1000000007) % 1000000007);
}
int main() {
  doit();
  return 0;
}
