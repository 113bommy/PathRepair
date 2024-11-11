#include <bits/stdc++.h>
using namespace std;
long long pwr(long long base, long long p, long long mod = (1000000007LL)) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
const int N = 200000;
int n, arr[N + 5], pos[N + 5];
vector<int> multiples[N + 5];
long long cnt[N + 5], minval[4 * N + 5], maxval[4 * N + 5], sumval[4 * N + 5],
    lazy[4 * N + 5];
void build(int node, int s, int e) {
  if (s > e) return;
  if (s == e) {
    minval[node] = maxval[node] = sumval[node] = s;
    return;
  }
  int mid = (s + e) / 2;
  build((2 * (node)), s, mid);
  build((2 * (node) + 1), mid + 1, e);
  minval[node] = min(minval[(2 * (node))], minval[(2 * (node) + 1)]);
  maxval[node] = max(maxval[(2 * (node))], maxval[(2 * (node) + 1)]);
  sumval[node] = sumval[(2 * (node))] + sumval[(2 * (node) + 1)];
}
int kth_query(int node, int s, int e, int threshold) {
  if (minval[node] >= threshold) return 0;
  if (s == e) return s;
  int mid = (s + e) / 2;
  if (minval[(2 * (node) + 1)] < threshold)
    return kth_query((2 * (node) + 1), mid + 1, e, threshold);
  return kth_query((2 * (node)), s, mid, threshold);
}
void update(int node, int s, int e, int lo, int hi, int val) {
  if (s > e || lo > hi || val <= 0) return;
  if (lazy[node] != 0) {
    minval[node] = maxval[node] = lazy[node];
    sumval[node] = (e - s + 1) * lazy[node];
    if (s != e) {
      lazy[(2 * (node))] = lazy[(2 * (node) + 1)] = lazy[node];
    }
    lazy[node] = 0;
  }
  if (lo > e || s > hi) return;
  if (s >= lo && e <= hi) {
    minval[node] = maxval[node] = val;
    sumval[node] = (e - s + 1) * val;
    if (s != e) {
      lazy[(2 * (node))] = lazy[(2 * (node) + 1)] = val;
    }
    return;
  }
  int mid = (s + e) / 2;
  update((2 * (node)), s, mid, lo, hi, val);
  update((2 * (node) + 1), mid + 1, e, lo, hi, val);
  minval[node] = min(minval[(2 * (node))], minval[(2 * (node) + 1)]);
  maxval[node] = max(maxval[(2 * (node))], maxval[(2 * (node) + 1)]);
  sumval[node] = sumval[(2 * (node))] + sumval[(2 * (node) + 1)];
}
long long sum_query(int node, int s, int e, int lo, int hi) {
  if (s > e) return 0;
  if (lazy[node] != 0) {
    minval[node] = maxval[node] = lazy[node];
    sumval[node] = (e - s + 1) * lazy[node];
    if (s != e) {
      lazy[(2 * (node))] = lazy[(2 * (node) + 1)] = lazy[node];
    }
    lazy[node] = 0;
  }
  if (lo > e || s > hi) return 0;
  if (s >= lo && e <= hi) return sumval[node];
  int mid = (s + e) / 2;
  return sum_query((2 * (node)), s, mid, lo, hi) +
         sum_query((2 * (node) + 1), mid + 1, e, lo, hi);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    pos[arr[i]] = i;
  }
  if (n <= 2) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= N; i++)
    for (int j = i; j <= N; j += i)
      if (pos[j] > 0) multiples[i].push_back(pos[j]);
  for (int i = 1; i <= N; i++) sort(multiples[i].begin(), multiples[i].end());
  build(1, 1, n);
  cnt[N + 1] = 1LL * n * (n + 1) - sum_query(1, 1, n, 1, n);
  for (int i = N; i >= 1; i--) {
    if ((int)multiples[i].size() < 2) {
      cnt[i] = cnt[i + 1];
      continue;
    }
    int k = multiples[i].size();
    int temp = kth_query(1, 1, n, multiples[i][k - 2]);
    int l = 1, r = min(multiples[i][0], temp);
    update(1, 1, n, l, temp, multiples[i][k - 2]);
    temp = kth_query(1, 1, n, multiples[i][k - 1]);
    l = multiples[i][0] + 1;
    r = min(multiples[i][1], temp);
    update(1, 1, n, l, temp, multiples[i][k - 1]);
    temp = kth_query(1, 1, n, n + 1);
    l = multiples[i][1] + 1;
    r = min(n, temp);
    update(1, 1, n, l, temp, n + 1);
    cnt[i] = 1LL * n * (n + 1) - sum_query(1, 1, n, 1, n);
  }
  long long ans = 0;
  for (int i = N; i >= 1; i--) ans += 1LL * i * (cnt[i + 1] - cnt[i]);
  printf("%lld\n", ans);
  return 0;
}
