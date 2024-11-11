#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
int n, k;
inline int ad(int& x, int& y) { return (x + y > P ? x + y - P : x + y); }
int A[200006], las[200006], pr[200006];
const int blo = 133;
int bel[200006];
pair<int, int> B[200006];
int S[200006];
int val[200006], gv[200006], lz[200006], cur;
void rebuild(int b) {
  int l = b * blo - blo + 1, r = b * blo;
  for (int i = (l), iend = (r); i <= iend; ++i) val[i] = val[i] + lz[b];
  lz[b] = 0;
  for (int i = (l), iend = (r); i <= iend; ++i) B[i] = make_pair(val[i], gv[i]);
  sort(B + l, B + r + 1);
  S[l] = B[l].second;
  for (int i = (l + 1), iend = (r); i <= iend; ++i)
    S[i] = ad(S[i - 1], B[i].second);
}
void add(int l, int r, int c) {
  ++l, ++r;
  if (bel[l] == bel[r]) {
    int b = bel[l];
    for (int i = (l), iend = (r); i <= iend; ++i) val[i] += c;
    rebuild(b);
    return;
  }
  for (int i = (l), iend = (bel[l] * blo); i <= iend; ++i) val[i] += c;
  rebuild(bel[l]);
  for (int i = (r), iend = (bel[r] * blo - blo + 1); i >= iend; --i)
    val[i] += c;
  rebuild(bel[r]);
  for (int i = (bel[l] + 1), iend = (bel[r] - 1); i <= iend; ++i) lz[i] += c;
}
int que() {
  int as = 0;
  for (int b = (1), bend = (bel[cur]); b <= bend; ++b) {
    int l = (b - 1) * blo + 1, r = b * blo;
    int ps =
        upper_bound(B + l, B + r + 1, make_pair(k - lz[b], 0x3f3f3f3f)) - B - 1;
    if (ps < l)
      continue;
    else
      as = ad(as, S[ps]);
  }
  return as;
}
void gt(int p, int c) {
  ++p;
  gv[p] = c;
  rebuild(bel[p]);
}
int dp[200006];
void solve() {
  cin >> n >> k;
  for (int i = (1), iend = (n); i <= iend; ++i)
    scanf("%d", A + i), las[i] = pr[A[i]], pr[A[i]] = i;
  for (int i = (1), iend = (n + 1); i <= iend; ++i) bel[i] = (i - 1) / blo + 1;
  dp[0] = 1;
  for (int i = (1), iend = (n); i <= iend; ++i) {
    cur = i + 1;
    add(las[i] + 1, i, 1);
    if (las[i]) add(las[las[i]] + 1, las[i], -1);
    gt(i, dp[i - 1]);
    dp[i] = que();
  }
  printf("%d\n", dp[n]);
}
signed main() { solve(); }
