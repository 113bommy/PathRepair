#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int arr[MAXN + 5];
pair<int, int> input[MAXN + 5];
int N, A, stop;
long long acc_sum[MAXN + 5];
int bin_search(long long m) {
  int lo = arr[0], hi = A - 1, mid;
  int ans;
  while (lo <= hi) {
    mid = (lo + hi) >> 1;
    int ii = upper_bound(arr, arr + stop, mid) - arr - 1;
    long long C = (long long)mid * (ii + 1) - acc_sum[ii];
    if (C <= m)
      lo = mid + 1, ans = mid;
    else
      hi = mid - 1;
  }
  return ans;
}
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
int main() {
  int Cf, Cm, x;
  long long m;
  scanf("%d%d%d%d%I64d", &N, &A, &Cf, &Cm, &m);
  for (int i = 0; i < N; i++) {
    scanf("%d", &input[i].first);
    input[i].second = i;
    arr[i] = input[i].first;
  }
  sort(arr, arr + N);
  for (int i = 0; i < N; i++)
    acc_sum[i] = (long long)arr[i] + (i ? acc_sum[i - 1] : 0);
  int max_count, min_val;
  int max_count_res = 0, min_val_res = 0;
  long long score = 0;
  stop = N;
  if (arr[0] == A) {
    score = (long long)N * Cf + (long long)A * Cm;
    max_count_res = N;
    min_val_res = A;
  } else {
    if (arr[N - 1] < A) {
      min_val_res = bin_search(m);
      max_count_res = 0;
      score = (long long)min_val_res * Cm;
    }
    max_count = 0;
    for (int i = N - 1; i >= 0; i--) {
      if (A - arr[i] > m) break;
      m -= A - arr[i];
      max_count++;
      stop--;
      if (!i)
        min_val = A;
      else
        min_val = bin_search(m);
      if ((long long)max_count * Cf + (long long)min_val * Cm > score) {
        score = (long long)max_count * Cf + (long long)min_val * Cm;
        max_count_res = max_count;
        min_val_res = min_val;
      }
    }
  }
  printf("%I64d\n", score);
  sort(input, input + N);
  for (int i = N - 1; i >= 0; i--) {
    if (max_count_res && input[i].first <= A) {
      input[i].first = A;
      max_count_res--;
    }
    if (input[i].first < min_val_res) input[i].first = min_val_res;
  }
  sort(input, input + N, cmp);
  for (int i = 0; i < N; i++) {
    printf("%d ", input[i].first);
  }
}
