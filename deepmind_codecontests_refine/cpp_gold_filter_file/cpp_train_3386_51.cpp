#include <bits/stdc++.h>
using namespace std;
vector<long long> M;
vector<long long> B;
bool bad(int l1, int l2, int l3, int forward) {
  if (forward)
    return (B[l1] - B[l2]) * (M[l3] - M[l1]) >=
           (B[l1] - B[l3]) * (M[l2] - M[l1]);
  return (B[l2] - B[l1]) * (M[l1] - M[l3]) <= (B[l3] - B[l1]) * (M[l1] - M[l2]);
}
void add(long long m, long long b, bool forward = 0) {
  M.push_back(m);
  B.push_back(b);
  while (M.size() >= 3 &&
         bad(M.size() - 3, M.size() - 2, M.size() - 1, !forward)) {
    M.erase(M.end() - 2);
    B.erase(B.end() - 2);
  }
}
long long Query(int p, long long x) { return M[p] * x + B[p]; }
long long read(long long x) {
  int l = -1, r = M.size() - 1;
  while ((r - l) > 1) {
    int m = (l + r) / 2;
    if (Query(m, x) <= Query(m + 1, x))
      l = m;
    else
      r = m;
  }
  return Query(r, x);
}
const int maxN = 200100;
long long fsumf[maxN], fsumr[maxN], n, a[maxN];
int main() {
  scanf("%I64d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 1; i <= n; i++) fsumf[i] += fsumf[i - 1] + i * a[i];
  for (int i = n; i >= 1; i--) fsumr[i] += fsumr[i + 1] + i * a[i];
  long long csum = 0, ans = fsumf[n];
  for (int i = 1; i <= n; i++) {
    if (i != 1) ans = max(ans, fsumf[i - 1] + fsumr[i + 1] + csum + read(a[i]));
    add(i, -csum);
    csum += a[i];
  }
  M.clear(), B.clear();
  csum = 0;
  for (int i = n; i >= 1; i--) {
    if (i != n) ans = max(ans, fsumf[i - 1] + fsumr[i + 1] - csum + read(a[i]));
    add(i, csum, 1);
    csum += a[i];
  }
  printf("%I64d\n", ans);
}
