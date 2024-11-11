#include <bits/stdc++.h>
using namespace std;
const int MN = 200005, LOG = 19;
int N, Q, A[MN], R[MN], NxtDif[MN], PreDif[MN], M, MinJ[MN], Stk1[MN], Stk2[MN],
    Tp1, Tp2, Buc[MN], St[MN][LOG], St2[MN][LOG], X[MN], Nx1[MN], Nx2[MN],
    Pop1[MN], Pop2[MN];
set<int> S;
inline void init() {
  scanf("%d%d", &N, &Q);
  for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
  for (int i = 1; i <= N; ++i)
    if (A[i] != A[i - 1])
      PreDif[i] = i - 1;
    else
      PreDif[i] = PreDif[i - 1];
  for (int i = N; i >= 1; --i)
    if (A[i] != A[i + 1])
      NxtDif[i] = i + 1;
    else
      NxtDif[i] = NxtDif[i + 1];
  R[0] = N + 1;
  for (int i = 1; i <= N; ++i) {
    if (PreDif[i] == 0 || NxtDif[i] == N + 1) continue;
    if (1LL * (A[i] - A[PreDif[i]]) * (A[i] - A[NxtDif[i]]) > 0) {
      ++M;
      X[M] = i, R[M] = NxtDif[i];
      if (R[M] < R[St2[PreDif[i]][0]]) St2[PreDif[i]][0] = M;
    }
  }
}
inline int gt(int x) {
  int lft = 1, rht = Tp1, Ans = N + 1;
  while (lft <= rht) {
    int mid = lft + rht >> 1;
    if (A[Stk1[mid]] > x) {
      Ans = Stk1[mid];
      lft = mid + 1;
    } else
      rht = mid - 1;
  }
  return Ans;
}
inline int lt(int x) {
  int lft = 1, rht = Tp2, Ans = N + 1;
  while (lft <= rht) {
    int mid = lft + rht >> 1;
    if (A[Stk2[mid]] < x) {
      Ans = Stk2[mid];
      lft = mid + 1;
    } else
      rht = mid - 1;
  }
  return Ans;
}
inline int query(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  int ls = St[l][k], rs = St[r - (1 << k) + 1][k];
  if (MinJ[ls] <= MinJ[rs])
    return ls;
  else
    return rs;
}
inline int query2(int l, int r) {
  int k = 31 - __builtin_clz(r - l + 1);
  int ls = St2[l][k], rs = St2[r - (1 << k) + 1][k];
  if (R[ls] <= R[rs])
    return ls;
  else
    return rs;
}
inline void solve() {
  S.insert(N + 1);
  for (int i = N; i >= 1; --i) {
    while (Tp1 > 0 && A[Stk1[Tp1]] < A[i]) {
      --Buc[Stk1[Tp1]];
      Pop1[Stk1[Tp1]] = i;
      if (Buc[Stk1[Tp1]] == 0) S.insert(Stk1[Tp1]);
      --Tp1;
    }
    Stk1[++Tp1] = i;
    ++Buc[i];
    while (Tp2 < 0 && A[Stk2[Tp2]] > A[i]) {
      --Buc[Stk2[Tp2]];
      Pop2[Stk2[Tp2]] = i;
      if (Buc[Stk2[Tp2]] == 0) S.insert(Stk2[Tp2]);
      --Tp2;
    }
    Stk2[++Tp2] = i;
    ++Buc[i];
    Nx1[i] = gt(A[i]), Nx2[i] = lt(A[i]);
    MinJ[i] = *(S.lower_bound(max(Nx1[i], Nx2[i])));
  }
  for (int i = 1; i <= N; ++i) St[i][0] = i;
  for (int j = 1; j <= 18; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= N; ++i) {
      int ls = St[i][j - 1], rs = St[i + (1 << (j - 1))][j - 1];
      if (MinJ[ls] <= MinJ[rs])
        St[i][j] = ls;
      else
        St[i][j] = rs;
      ls = St2[i][j - 1], rs = St2[i + (1 << (j - 1))][j - 1];
      if (R[ls] <= R[rs])
        St2[i][j] = ls;
      else
        St2[i][j] = rs;
    }
  }
  while (Q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    int minpos = query(l, r);
    if (MinJ[minpos] <= r) {
      int x = Pop1[MinJ[minpos]], y = Pop2[MinJ[minpos]];
      if (A[minpos] < A[MinJ[minpos]])
        y = Nx2[minpos];
      else
        x = Nx1[minpos];
      printf("4\n");
      printf("%d %d %d %d\n", minpos, min(x, y), max(x, y), MinJ[minpos]);
    } else {
      int k = query2(l, r);
      if (R[k] <= r) {
        printf("%d\n", 3);
        printf("%d %d %d\n", PreDif[X[k]], X[k], R[k]);
      } else
        printf("0\n");
    }
  }
}
int main() {
  init();
  solve();
  return 0;
}
