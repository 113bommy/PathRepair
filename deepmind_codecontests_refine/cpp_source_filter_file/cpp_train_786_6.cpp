#include <bits/stdc++.h>
using namespace std;
inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int resetBit(int N, int pos) { return N = N & ~(1 << pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }
int n;
struct data {
  int xx, yy, id;
} A[100000 + 10];
bool operator<(data a, data b) {
  if (a.xx == b.xx) return a.yy < b.yy;
  return a.xx < b.xx;
}
int L[100000 + 10], seq[100000 + 10], dp[100000 + 10];
int LIS(int *seq, int *dp, int N) {
  int len = 0;
  int retSpecial;
  for (int i = 1; i <= N; ++i) {
    int lo = 1, hi = len;
    while (lo <= hi) {
      int m = (lo + hi) / 2;
      if (L[m] < seq[i])
        lo = m + 1;
      else
        hi = m - 1;
    }
    L[lo] = seq[i], dp[i] = lo;
    if (len < lo) len = lo;
  }
  return len;
}
int LIS_Special(int *seq, int *dp, int N) {
  int len = 1;
  int retSpecial;
  int st;
  for (int i = 1; i <= N; i++) {
    if (A[i].id == N) {
      st = i;
      break;
    }
  }
  L[1] = seq[st];
  for (int i = st + 1; i <= N; ++i) {
    int lo = 1, hi = len;
    while (lo <= hi) {
      int m = (lo + hi) / 2;
      if (L[m] < seq[i])
        lo = m + 1;
      else
        hi = m - 1;
    }
    if (lo > 1) {
      L[lo] = seq[i], dp[i] = lo;
      if (len < lo) len = lo;
    }
  }
  return len - 1;
}
void solve() {
  int i;
  for (i = 1; i <= n; i++) {
    data tmp;
    tmp.xx = A[i].xx + A[i].yy;
    tmp.yy = -A[i].xx + A[i].yy;
    A[i] = tmp;
  }
  sort(A + 1, A + n + 1);
  for (i = 1; i <= n; i++) seq[i] = A[i].yy;
  int ans2 = LIS(seq, dp, n);
  n++;
  A[n] = {0, 0, n};
  sort(A + 1, A + n + 1);
  for (i = 1; i <= n; i++) seq[i] = A[i].yy;
  int ans1 = LIS_Special(seq, dp, n);
  printf("%d %d\n", ans1, ans2);
}
int main() {
  int i, j, cs, t, v;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d %d", &A[i].xx, &A[i].yy), A[i].id = i;
  scanf("%d", &v);
  for (i = 1; i <= n; i++) A[i].yy *= v;
  solve();
  return 0;
}
