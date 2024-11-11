#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6 + 10;
long long N, M, val[MAXN], C[MAXN];
long long ask(long long);
void add(long long);
int main() {
  scanf("%lld", &N);
  long long p = (3 * N) % 2, a = (7 * N + 1) % 2;
  long long ans = 0;
  for (long long i = 1; i <= N; i++) {
    scanf("%lld", val + i);
    add(val[i]);
    ans += (i - ask(val[i]));
  }
  if (ans % 2 == p % 2) {
    printf("Petr\n");
  } else {
    printf("Um_nik\n");
  }
  return 0;
}
void add(long long x) {
  while (x <= N) {
    C[x]++;
    x += (x & (-x));
  }
}
long long ask(long long x) {
  long long ret = 0;
  while (x) {
    ret += C[x];
    x -= (x & (-x));
  }
  return ret;
}
