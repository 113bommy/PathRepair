#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
const long long N = 1e5 + 10;
vector<long long> pre1, pre2;
long long n;
long long unprime[N];
long long prime[N / 10], tot;
void init() {
  unprime[1] = 1;
  for (long long i = 2; i < N; i++) {
    if (!unprime[i]) {
      prime[++tot] = i;
    }
    for (long long j = 1; j <= tot && i * prime[j] < N; j++) {
      unprime[i * prime[j]] = 1;
      if (i % prime[j] == 0) break;
    }
  }
}
long long A(long long x = 1) {
  if (x > n) return 0;
  printf("A %lld \n", x);
  fflush(stdout);
  long long k;
  scanf("%lld", &k);
  return k;
}
long long B(long long x) {
  if (x > n) return 0;
  printf("B %lld\n", x);
  fflush(stdout);
  long long k;
  scanf("%lld", &k);
  return k;
}
long long C(long long x) {
  printf("C %lld\n", x);
  fflush(stdout);
  exit(0);
}
signed main() {
  init();
  n = read();
  for (long long i = 2; i <= n; i++) {
    if (!unprime[i]) {
      if (i <= 316)
        pre1.push_back(i);
      else
        pre2.push_back(i);
    }
  }
  long long res = 1;
  for (long long x : pre1) {
    B(x);
    for (long long i = x;; i *= x) {
      if (A(i))
        res *= x;
      else
        break;
    }
  }
  long long tmp1 = pre2.size();
  if (res != 1) {
    for (long long i = 0; i < tmp1; i += 100) {
      long long tmp2 = min(tmp1, i + 100);
      for (long long j = i; j < tmp2; j++) {
        if (A(res * pre2[j])) C(res * pre2[j]);
      }
    }
    C(res);
  } else {
    long long cnt = tmp1 + 1;
    for (long long i = 0; i < tmp1; i += 100) {
      long long tmp2 = min(tmp1, i + 100);
      for (long long j = i; j <= tmp2; j++) {
        B(pre2[j]);
      }
      cnt -= min(100ll, tmp1 - i);
      if (A(1) != cnt) {
        for (long long j = i; j < tmp2; j++) {
          if (A(pre2[j])) C(pre2[j]);
        }
      }
    }
    C(1);
  }
}
