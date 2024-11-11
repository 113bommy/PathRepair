#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 200000;
int n, want, t5, t1;
int x[MAXN];
long long q[5][MAXN];
int qhead[5], qtail[5];
void run() {
  scanf("%d%d%d%d", &n, &want, &t5, &t1);
  for (int i = (0); i < (n); ++i) scanf("%d", &x[i]);
  sort(x, x + n);
  if (5 * t1 < t5) t5 = 5 * t1;
  long long ret = LLONG_MAX;
  for (int off = (0); off < (5); ++off) {
    for (int k = (0); k < (5); ++k) qhead[k] = qtail[k] = 0;
    int cnt = 0;
    long long sum = 0;
    for (int i = (0); i < (n); ++i) {
      int n1 = (off - x[i]) % 5;
      if (n1 < 0) n1 += 5;
      long long cost = n1 * t1 - (long long)(x[i] + n1 - off) / 5 * t5;
      q[n1][qhead[n1]++] = cost;
      sum += cost;
      ++cnt;
      if (cnt > want) {
        int idx = -1;
        for (int k = (0); k < (5); ++k)
          if (qtail[k] < qhead[k] &&
              (idx == -1 || q[k][qtail[k]] > q[idx][qtail[idx]]))
            idx = k;
        assert(idx != -1);
        sum -= q[idx][qtail[idx]++];
        --cnt;
      }
      if (cnt == want) {
        long long cur = sum + (long long)(x[i] + n1 - off) / 5 * t5 * cnt;
        if (cur < ret) ret = cur;
      }
    }
  }
  printf("%I64d\n", ret);
}
int main() {
  run();
  return 0;
}
