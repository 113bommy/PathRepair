#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int N, M;
int L[MAXN];
vector<long long> A[MAXN];
vector<long long> sum[MAXN];
long long go(int a, long long h) {
  long long ret = 0;
  int idx = lower_bound(A[a].begin(), A[a].end(), h + L[a]) - A[a].begin();
  if (idx > 0) ret += (h + L[a]) * idx - sum[a][idx - 1];
  int b = a;
  a /= 2;
  long long cur = L[b] - L[a];
  while (a > 0) {
    int idx =
        lower_bound(A[a].begin(), A[a].end(), h - cur + L[a]) - A[a].begin();
    if (idx > 0) ret += (h - cur + L[a]) * idx - sum[a][idx - 1];
    idx =
        lower_bound(A[b].begin(), A[b].end(), h - cur - (L[b] - L[a]) + L[a]) -
        A[b].begin();
    if (idx > 0)
      ret -= (h - cur - (L[b] - L[a]) + L[a]) * idx - sum[b][idx - 1];
    b = a;
    a /= 2;
    cur += L[b] - L[a];
  }
  return ret;
}
int main() {
  scanf("%d %d", &N, &M);
  for (int i = 2, l; i <= N; i++) {
    scanf("%d", &l);
    L[i] = L[i / 2] + l;
  }
  for (int i = N; i >= 1; i--) {
    A[i].push_back(L[i]);
    if (2 * i <= N) A[i].insert(A[i].end(), A[2 * i].begin(), A[2 * i].end());
    if (2 * i + 1 <= N)
      A[i].insert(A[i].end(), A[2 * i + 1].begin(), A[2 * i + 1].end());
    sort(A[i].begin(), A[i].end());
    for (int j = 0; j < A[i].size(); j++) {
      sum[i].push_back(A[i][j]);
      if (sum[i].size() > 1) sum[i][j] += sum[i][j - 1];
    }
  }
  for (int i = 0, a, h; i < M; i++) {
    scanf("%d %d", &a, &h);
    printf("%I64d\n", go(a, h));
  }
  return 0;
}
