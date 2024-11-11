#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int prime[N + 10], s[N + 10];
bool is[N + 10];
int main() {
  for (int i = 2; i <= N; ++i) {
    if (!is[i]) prime[++prime[0]] = i;
    for (int j = 1; j <= prime[0] && i * prime[j] <= N; ++j) {
      is[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  for (int i = 1; i <= prime[0]; ++i) s[prime[i]] = 1;
  for (int i = 1; i <= N; ++i) s[i] += s[i - 1];
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", 1 + s[n] - s[(int)sqrt(n)]);
  }
  return 0;
}
