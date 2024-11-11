#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
int n;
long long L, t, a[maxn * 2];
void Brute(void) {
  long long ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n * 2 && a[j] - a[i] <= t * 2) {
      ++j;
    }
    ans += j - i - 1;
  }
  double out = ans / 4.0;
  printf("%.10lf\n", out);
}
int bit[maxn];
int Low(int i) { return i & -i; }
void Add(int i, int x) {
  for (; i < n; i += Low(i + 1)) {
    bit[i] += x;
  }
}
int Sum(int i) {
  int sum = 0;
  for (--i; i >= 0; i -= Low(i + 1)) {
    sum += bit[i];
  }
  return sum;
}
int Sum2(long long lb, long long ub) {
  lb = lower_bound(a, a + n, lb) - a;
  ub = lower_bound(a, a + n, ub) - a;
  if (lb <= ub) {
    return Sum(ub) - Sum(lb);
  } else {
    return Sum(ub) - Sum(lb) + Sum(n);
  }
}
void Solve(void) {
  long long cnt = 0;
  long long a_ = 4 * t % L;
  for (int i = 0; i < n; ++i) {
    long long me = (2 * t + a[i]) % L;
    long long ub = (me + 1) % L, lb = (me - a_ + L) % L;
    cnt += Sum2(lb, ub);
    Add(i, 1);
  }
  long long ans = (long long)n * (n - 1) / 2 * (4 * t / L);
  ans += cnt;
  double out = ans / 4.0;
  printf("%.10lf\n", out);
}
int main(void) {
  scanf("%d%lld%lld", &n, &L, &t);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);
    a[n + i] = L + a[i];
  }
  if (2 * t < L) {
    Brute();
  } else {
    Solve();
  }
  return 0;
}
