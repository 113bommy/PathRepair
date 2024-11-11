#include <bits/stdc++.h>
using namespace std;
long long sum[200005];
pair<int, int> a[200005];
int main() {
  long long t, i, j, n, m, res = 0, first, second, s, idx;
  vector<tuple<long long, long long, long long, long long>> vec;
  vector<pair<long long, long long>> vec2;
  for (i = 0; i <= 200001; i++) {
    sum[i] = (long long)1e17;
  }
  scanf("%I64d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%I64d %I64d", &a[i].first, &a[i].second);
    vec.emplace_back(a[i].first + a[i].second, a[i].first, a[i].second, i);
  }
  sort(vec.begin(), vec.end());
  for (i = 0; i < vec.size(); i++) {
    tie(s, first, second, idx) = vec[i];
    sum[idx] = min(first + second, min(sum[idx - 1], sum[idx + 1]) + 1);
    if (sum[idx] < first) {
      printf("-1\n");
      return 0;
    }
    res += sum[idx] - first;
  }
  for (idx = 1; idx <= n; idx++) {
    res -= sum[idx];
    if (idx > 1 && sum[idx] > sum[idx - 1] + 1) {
      sum[idx] = sum[idx - 1] + 1;
    }
    if (idx < n && sum[idx] > sum[idx + 1] + 1) {
      sum[idx] = sum[idx + 1] + 1;
    }
    res += sum[idx];
  }
  for (idx = n; idx >= 1; idx--) {
    res -= sum[idx];
    if (idx > 1 && sum[idx] > sum[idx - 1] + 1) {
      sum[idx] = sum[idx - 1] + 1;
    }
    if (idx < n && sum[idx] > sum[idx + 1] + 1) {
      sum[idx] = sum[idx + 1] + 1;
    }
    res += sum[idx];
    if (sum[idx] < a[idx].first) {
      printf("-1\n");
      return 0;
    }
  }
  printf("%I64d\n", res);
  for (i = 1; i <= n; i++) {
    printf("%I64d ", sum[i]);
  }
  printf("\n");
  return 0;
}
