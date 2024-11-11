#include <bits/stdc++.h>
using namespace std;
long long n;
long long dptb[1000005];
bool valid(long long x) { return (3 * x * x + 2 * x) <= n; }
void preprocess() {}
int main() {
  preprocess();
  scanf("%I64d", &n);
  long long l, r, mid, jmp;
  long long curr = 0, curc = 0;
  l = 0, r = 1e9;
  while (l <= r) {
    mid = (l + r) / 2;
    if (valid(mid)) {
      jmp = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  curr = -2 * jmp, curc = jmp;
  n -= 3 * jmp * jmp + 2 * jmp;
  int k;
  jmp++;
  k = min(n, jmp);
  curc += k;
  curr += 2 * k;
  n -= k;
  k = max(0ll, min(n, jmp - 1));
  curc -= k;
  curr += 2 * k;
  n -= k;
  k = min(n, jmp);
  curc -= 2 * k;
  n -= k;
  k = min(n, jmp);
  curc -= k;
  curr -= 2 * k;
  n -= k;
  k = min(n, jmp);
  curc += k;
  curr -= 2 * k;
  n -= k;
  k = min(n, jmp);
  curc += 2 * k;
  n -= k;
  printf("%I64d %I64d\n", curc, curr);
  return 0;
}
