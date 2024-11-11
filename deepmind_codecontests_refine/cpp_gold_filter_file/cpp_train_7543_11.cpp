#include <bits/stdc++.h>
using namespace std;
const string problemName = "";
const string inputFile = problemName + ".in";
const string outputFile = problemName + ".out";
const int INF = (1LL << 31) - 1;
const long long int LINF = (1LL << 62) - 1;
const int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};
const int MOD = (int)(1e9) + 7;
const int NMAX = 100000 + 5;
const int MMAX = 100000 + 5;
const int KMAX = 100000 + 5;
const int PMAX = 100000 + 5;
const int LMAX = 100000 + 5;
const int VMAX = 100000 + 5;
int N, M, pref, suf;
int A[NMAX];
int B[NMAX];
long long int sol;
bool is_palindrome(int lo, int hi) {
  if (lo >= hi) return 1;
  if (A[lo] == A[hi]) return is_palindrome(lo + 1, hi - 1);
  return 0;
}
bool maybe_palindrome(int lo, int hi) {
  int i, ok = 0;
  for (i = lo; i <= hi; i++) B[A[i]]++;
  for (i = 1; i < NMAX; i++)
    if (B[i] % 2 && ok)
      return 0;
    else if (B[i] % 2)
      ok = 1;
  return 1;
}
bool maybe_palindrome() {
  int i, ok = 0;
  for (i = 1; i < NMAX; i++)
    if ((B[i] % 2 && ok) || (B[i] < 0))
      return 0;
    else if (B[i] % 2)
      ok = 1;
  return 1;
}
int main() {
  int i, x, y, lo, mi, mi2, hi, ok;
  scanf("%d", &N);
  for (i = 1; i <= N; i++) scanf("%d", &A[i]);
  if (is_palindrome(1, N)) {
    printf("%lld\n", N * 1LL * (N + 1) / 2);
    return 0;
  }
  if (!maybe_palindrome(1, N)) {
    printf("%d\n", 0);
    return 0;
  }
  for (x = 1, y = N; x <= y && A[x] == A[y]; x++, y--)
    ;
  M = y - x + 1;
  pref = suf = INF;
  for (lo = x, hi = y; lo <= hi;) {
    mi = (lo + hi) / 2;
    mi2 = N - mi + 1;
    if (is_palindrome(mi + 1, mi2 - 1)) {
      memset(B, 0, sizeof(B));
      for (i = x; i <= mi; i++) B[A[i]]++;
      for (i = y; i >= max(mi + 1, mi2); i--) B[A[i]]--;
      ok = maybe_palindrome();
    } else
      ok = 0;
    if (ok) {
      pref = min(pref, mi - x + 1);
      hi = mi - 1;
    } else
      lo = mi + 1;
  }
  for (lo = x, hi = y; lo <= hi;) {
    mi = (lo + hi) / 2;
    mi2 = N - mi + 1;
    if (is_palindrome(mi2 + 1, mi - 1)) {
      memset(B, 0, sizeof(B));
      for (i = y; i >= mi; i--) B[A[i]]++;
      for (i = x; i <= min(mi - 1, mi2); i++) B[A[i]]--;
      ok = maybe_palindrome();
    } else
      ok = 0;
    if (ok) {
      suf = min(suf, y - mi + 1);
      lo = mi + 1;
    } else
      hi = mi - 1;
  }
  sol = (N - M) / 2 + 1;
  sol *= (N - M) / 2 + 2 * M + 1 - pref - suf;
  printf("%lld\n", sol);
  return 0;
}
