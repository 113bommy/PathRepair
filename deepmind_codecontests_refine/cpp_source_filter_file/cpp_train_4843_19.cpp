#include <bits/stdc++.h>
using namespace std;
struct node {
  long long val;
  int id;
} s[100005];
long long ans, sum[100005];
long long n, A, cf, cm, m;
bool cmp1(node a, node b) { return a.val < b.val; }
bool cmp2(node a, node b) { return a.id < b.id; }
int main() {
  while (scanf("%lld%lld%lld%lld%lld", &n, &A, &cf, &cm, &m) == 5) {
    for (int i = 0; i < n; i++) {
      scanf("%lld", &s[i].val);
      s[i].id = i;
    }
    sort(s, s + n, cmp1);
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
      sum[i + 1] = sum[i] + s[i].val;
    }
    ans = -1;
    long long ansi, ansj, ansmin;
    long long tmpmin, left, cost, tmp;
    for (int i = 0, j = 0; i < n; i++) {
      cost = (n - i) * A - (sum[n] - sum[i]);
      if (cost > m)
        continue;
      else {
        tmp = (n - i) * cf;
        left = m - cost;
      }
      while (j < i && s[j].val * j - sum[j] <= left) {
        ++j;
      }
      if (j == 0) {
        tmpmin = A;
      } else {
        tmpmin = min((left + sum[j]) / j, A);
      }
      tmp += tmpmin * cm;
      if (tmp > ans) {
        ansi = i;
        ansj = j - 1;
        ans = tmp;
        ansmin = tmpmin;
      }
    }
    for (int i = ansi; i < n; i++) s[i].val = A;
    for (int i = 0; i <= ansj; i++) s[i].val = ansmin;
    sort(s, s + n, cmp2);
    printf("%lld\n", ans);
    bool first = true;
    for (int i = 0; i < n; i++) {
      if (first) {
        printf("%lld", s[i].val);
        first = false;
      } else
        printf(" %lld", s[i].val);
    }
    printf("\n");
  }
  return 0;
}
