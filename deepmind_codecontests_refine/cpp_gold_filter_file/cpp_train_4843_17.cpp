#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int n, A, cf, cm;
pair<int, int> arr[N];
long long sum[N + 1], m;
int g(long long val, int n2, bool modify) {
  if (val >= 1LL * A * n2 - sum[n2]) {
    if (modify)
      for (int i = 0; i < n2; i++) arr[i].first = A;
    return A;
  }
  if (!val) return arr[0].first;
  int from = arr[0].first, to = A;
  while (from < to) {
    int middle = (from + to + 1) / 2;
    int pos = lower_bound(arr, arr + n2, make_pair(middle + 1, -1)) - arr;
    if (val >= 1LL * pos * middle - sum[pos])
      from = middle;
    else
      to = middle - 1;
  }
  if (modify)
    for (int i = 0; i < n2; i++)
      if (arr[i].first < from) arr[i].first = from;
  return from;
}
long long f(int maxi, bool modify) {
  long long val = m;
  if (maxi < n and arr[n - maxi - 1].first == A) return -1;
  if (val < 1LL * A * maxi - sum[n] + sum[n - maxi]) return -1;
  val -= 1LL * A * maxi - sum[n] + sum[n - maxi];
  if (modify) {
    for (int i = 1; i <= maxi; i++) arr[n - i].first = A;
  }
  return 1LL * cf * maxi + 1LL * cm * g(val, n - maxi, modify);
}
int main() {
  scanf("%d %d %d %d %lld", &n, &A, &cf, &cm, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i].first);
    arr[i].second = i;
  }
  sort(arr, arr + n);
  for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i - 1].first;
  long long best = -1;
  int id = -1;
  for (int i = 0; i <= n; i++) {
    long long aux = f(i, false);
    if (aux > best) {
      best = aux;
      id = i;
    }
  }
  printf("%lld\n", f(id, true));
  sort(arr, arr + n,
       [](pair<int, int> i, pair<int, int> j) { return i.second < j.second; });
  for (int i = 0; i < n; i++) printf("%d ", arr[i].first);
  return 0;
}
