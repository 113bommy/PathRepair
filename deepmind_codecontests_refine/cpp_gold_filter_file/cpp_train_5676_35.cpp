#include <bits/stdc++.h>
using namespace std;
long long sol;
int mn, eq;
int K, cf, cm;
long long M;
long long upd(int m, int ct) {
  long long tmp;
  tmp = 1LL * m * cm + 1LL * ct * cf;
  if (tmp > sol) {
    sol = tmp;
    mn = m, eq = ct;
  }
  return tmp;
}
pair<int, int> A[100010];
long long pref[100010];
int N;
int search(long long use, int n) {
  int low, high, k, mid;
  low = 0, high = K;
  long long need;
  while (low < high) {
    mid = low + (high - low + 1) / 2;
    k = upper_bound(A, A + n, make_pair(mid, N)) - A - 1;
    need = k >= 0 ? 1LL * mid * (k + 1) - pref[k] : 0;
    if (use >= need) {
      low = mid;
    } else {
      high = mid - 1;
    }
  }
  return low;
}
void compute() {
  int i;
  long long used, left;
  used = left = 0;
  for (i = 0; i < N; ++i) {
    used += (K - A[i].first);
    pref[i] = i ? A[i].first + pref[i - 1] : A[i].first;
  }
  for (i = 0; i <= N; ++i) {
    if (used > M) {
      used -= (K - A[i].first);
      continue;
    }
    left = M - used;
    upd(search(left, i), N - i);
    used -= (K - A[i].first);
  }
}
int comp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
void cons() {
  int i;
  for (i = 0; i < N; ++i) A[i].first = max(A[i].first, mn);
  while (eq--) A[--i].first = K;
}
int main() {
  int i;
  scanf("%d%d%d%d%lld", &N, &K, &cf, &cm, &M);
  for (i = 0; i < N; ++i) {
    scanf("%d", &A[i].first);
    A[i].second = i;
  }
  sort(A, A + N);
  compute();
  cons();
  sort(A, A + N, comp);
  printf("%lld\n", sol);
  for (i = 0; i < N; ++i) printf("%d ", A[i].first);
  return 0;
}
