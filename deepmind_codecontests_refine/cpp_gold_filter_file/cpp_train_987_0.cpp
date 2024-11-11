#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
const int MAXN = 100000 + 1000;
struct node {
  long long m, s;
  bool operator<(const node& b) const { return m < b.m; }
} num[MAXN];
long long sum[MAXN];
long long M[MAXN];
int n, d;
int main() {
  while (scanf("%d%d", &n, &d) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%I64d%I64d", &num[i].m, &num[i].s);
    sort(num + 1, num + n + 1);
    sum[0] = 0;
    M[0] = 0;
    for (int i = 1; i <= n; i++) M[i] = num[i].m;
    M[n + 1] = INF;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + num[i].s;
    sum[n + 1] = sum[n];
    long long ans = 0;
    for (int i = 1; i <= n + 1; i++) {
      int s = i - 1;
      int e = ((long long)upper_bound(M + 1, M + n + 2,
                                      (long long)M[i] + (long long)d - 1) -
               (long long)(M + 1)) /
              sizeof(long long);
      long long temp = sum[e] - sum[s];
      ans = max(ans, temp);
    }
    printf("%I64d\n", ans);
  }
}
