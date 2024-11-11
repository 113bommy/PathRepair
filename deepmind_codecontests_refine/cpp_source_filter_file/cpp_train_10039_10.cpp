#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int k, d, opl, opr;
int S[N * 4], L[N * 4], M[N * 4];
inline void Shift(int id) {
  M[(id << 1)] += L[id];
  L[(id << 1)] += L[id];
  M[((id << 1) ^ 1)] += L[id];
  L[((id << 1) ^ 1)] += L[id];
  L[id] = 0;
}
void Add(int le, int ri, int val, int id, int l, int r) {
  if (ri <= l || r <= le) return;
  if (le <= l && r <= ri) {
    L[id] += val;
    M[id] += val;
    return;
  }
  Shift(id);
  Add(le, ri, val, (id << 1), l, (l + r >> 1));
  Add(le, ri, val, ((id << 1) ^ 1), (l + r >> 1), r);
  M[id] = min(M[(id << 1)], M[((id << 1) ^ 1)]);
}
int Get(int id, int l, int r) {
  if (r - l < 2) return l;
  Shift(id);
  if (M[((id << 1) ^ 1)] <= k) return (Get(((id << 1) ^ 1), (l + r >> 1), r));
  return (Get((id << 1), l, (l + r >> 1)));
}
void Solve(vector<int> &A, int jp) {
  int Mx = 0, rb, n = rb = A.size();
  map<int, int> P;
  vector<int> MX, MN;
  MX.push_back(n);
  MN.push_back(n);
  for (int i = n - 1; ~i; i--) {
    A[i] /= d;
    if (P.count(A[i]) && P[A[i]] < rb)
      Add(P[A[i]], rb, N + N, 1, 0, n), rb = P[A[i]];
    P[A[i]] = i;
    while (MX.size() > 1 && A[MX.back()] < A[i])
      Add(MX.back(), MX[MX.size() - 2], A[i] - A[MX.back()], 1, 0, n),
          MX.pop_back();
    while (MN.size() > 1 && A[MN.back()] > A[i])
      Add(MN.back(), MN[MN.size() - 2], A[MN.back()] - A[i], 1, 0, n),
          MN.pop_back();
    MX.push_back(i);
    MN.push_back(i);
    Add(i + 1, n, -1, 1, 0, n);
    int r = Get(1, 0, n);
    if ((opr - opl < r - i) || (opr - opl == r - i && i + jp < opl))
      opl = i + jp, opr = r + jp;
  }
  for (int i = 0; i <= n * 4; i++) S[i] = L[i] = M[i] = 0;
}
int main() {
  int n;
  vector<int> A;
  scanf("%d%d%d", &n, &k, &d);
  if (d == 0) {
    int p = INT_MAX, c = 0;
    for (int i = 0, a; i < n; i++) {
      scanf("%d", &a);
      if (a != p) p = a, c = 0;
      c++;
      if (opr - opl < c) opr = i, opl = i - c + 1;
    }
    return !printf("%d %d", opl + 1, opr + 1);
  }
  for (int i = 0, a; i < n; i++) {
    scanf("%d", &a);
    a += 1e9;
    if (A.size() && a % d != A.back() % d) Solve(A, i - A.size()), A.clear();
    A.push_back(a);
  }
  Solve(A, n - A.size());
  return !printf("%d %d", opl + 1, opr + 1);
}
