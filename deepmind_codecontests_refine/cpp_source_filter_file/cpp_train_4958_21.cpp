#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5;
const int Maxk = 20;
const long long INF = 0x3f3f3f3f3f3f3f3f;
int N, K;
int A[Maxn + 5];
long long f[Maxk + 5][Maxn + 5];
int cnt[Maxn + 5];
int l, r;
long long ret;
long long calc_cost(int lef, int rig) {
  while (l < lef) {
    ret -= 1LL * cnt[A[l]] * (cnt[A[l]] - 1) / 2, cnt[A[l]]--;
    ret += 1LL * cnt[A[l]] * (cnt[A[l]] - 1) / 2, l++;
  }
  while (l > lef) {
    l--, ret -= 1LL * cnt[A[l]] * (cnt[A[l]] - 1) / 2;
    cnt[A[l]]++, ret += 1LL * cnt[A[l]] * (cnt[A[l]] - 1) / 2;
  }
  while (r < rig) {
    r++, ret -= 1LL * cnt[A[r]] * (cnt[A[r]] - 1) / 2;
    cnt[A[r]]++, ret += 1LL * cnt[A[r]] * (cnt[A[r]] - 1) / 2;
  }
  while (r > rig) {
    ret -= 1LL * cnt[A[r]] * (cnt[A[r]] - 1) / 2, cnt[A[r]]--;
    ret += 1LL * cnt[A[r]] * (cnt[A[r]] - 1) / 2, r--;
  }
  return ret;
}
void DFS(int now, int lb, int ub, int optl, int optr) {
  if (lb > ub) return;
  int pos;
  long long val = INF;
  int mid = (lb + ub) >> 1;
  for (int i = optl; i <= optr && i <= mid; i++) {
    long long tmp = f[now - 1][i - 1] + calc_cost(i, mid);
    if (tmp < val) val = tmp, pos = i;
  }
  f[now][mid] = val;
  DFS(now, lb, mid - 1, optl, pos);
  DFS(now, mid + 1, ub, pos, optr);
}
int main() {
  scanf("%d %d", &N, &K);
  for (int i = 1; i <= N; i++) scanf("%d", &A[i]);
  memset(f, 0x3f, sizeof f);
  cnt[A[1]] = 1, f[0][0] = 1, l = r = 1;
  for (int i = 1; i <= K; i++) DFS(i, 1, N, 1, N);
  printf("%lld\n", f[K][N]);
  return 0;
}
