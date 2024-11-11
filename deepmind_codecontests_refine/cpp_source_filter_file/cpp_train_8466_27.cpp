#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> p[10005];
long long n;
bool comp(pair<long long, long long> p1, pair<long long, long long> p2) {
  return p1.first * p2.second < p1.second * p2.first;
}
long long compDays(long long x) {
  long long ret = n;
  long long i;
  for (i = 0; i < n; ++i) ret += (p[i].first * x) / p[i].second;
  return ret;
}
int main() {
  int i;
  long long c, a, b;
  scanf("%d%I64d", &n, &c);
  for (i = 0; i < n; ++i) {
    scanf("%I64d%I64d", &a, &b);
    p[i] = pair<long long, long long>(a, b);
  }
  sort(p, p + n, comp);
  if (c < n) {
    printf("0\n");
    return 0;
  }
  long long high = (c - n) * (p[0].second + p[0].first + 5) / p[0].first;
  long long first = 0, cnt = high, step, mid;
  while (cnt > 0) {
    step = cnt / 2;
    mid = first + step;
    long long days = compDays(mid);
    if (days < c) {
      first = mid + 1;
      cnt -= (step + 1);
    } else
      cnt = step;
  }
  if (compDays(first) != c) {
    printf("0\n");
    return 0;
  }
  long long low = first;
  cnt = high - first + 1;
  while (cnt > 0) {
    step = cnt / 2;
    mid = first + step;
    long long days = compDays(mid);
    if (days <= c) {
      first = mid + 1;
      cnt -= (step + 1);
    } else
      cnt = step;
  }
  printf("%I64d\n", first - low);
  return 0;
}
