#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
int p[MAXN], N;
pair<long long, long long> a[MAXN];
int collin(int i, int j, int k) {
  return a[i].first * (a[j].second - a[k].second) +
             a[j].first * (a[k].second - a[i].second) +
             a[k].first * (a[i].second - a[j].second) ==
         0;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%I64d%I64d", &a[i].first, &a[i].second);
    p[i] = i;
  }
  sort(p + 1, p + N + 1, [](int i, int j) { return a[i] < a[j]; });
  int j = 3;
  while (collin(p[1], p[2], p[j])) j++;
  printf("%d %d %d\n", p[1], p[2], p[j]);
}
