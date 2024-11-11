#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:255000000")
bool firstout = 1;
template <class T>
T &minn(T &a, T b) {
  if (b < a) a = b;
  return a;
}
template <class T>
T &maxx(T &a, T b) {
  if (a < b) a = b;
  return a;
}
int &madd(int &a, int b) {
  a += b;
  if (a >= 1000000009) a -= 1000000009;
  return a;
}
int &msub(int &a, int b) {
  a -= b;
  if (a < 0) a += 1000000009;
  return a;
}
int &mmult(int &a, int b) { return a = (long long)a * b % 1000000009; }
int mdiv(long long a, long long b, long long m) {
  a = (a % m + m) % m;
  b = (b % m + m) % m;
  if (a % b == 0) return a / b;
  return (a + m * mdiv(-a, m, b)) / b;
}
int DX[4] = {-1, 0, 1, 0};
int DY[4] = {0, 1, 0, -1};
bool O[15][15];
pair<int, int> P[15 * 15], L[15 * 15], R[15 * 15];
int n, m, np, nl, nr, mm;
double io, jo;
bool A[2012][2012], AA[2012][2012];
multiset<double> smn, smx;
bool valid(int i, int j) { return 0 <= i && i < n && 0 <= j && j < n; }
pair<int, pair<int, int> > dfs(int i, int j) {
  pair<int, pair<int, int> > res, p;
  res = make_pair(1, make_pair(i, j));
  AA[i][j] = 0;
  int k, ii, jj;
  for (k = (0); k < (4); ++k) {
    ii = i + DX[k];
    jj = j + DY[k];
    if (valid(ii, jj) && AA[ii][jj]) {
      p = dfs(ii, jj);
      res.first += p.first;
      res.second.first += p.second.first;
      res.second.second += p.second.second;
    }
  }
  return res;
}
void dfsd(int i, int j, int k) {
  if (!A[i][j]) return;
  AA[i][j] = A[i][j];
  A[i][j] = 0;
  double d = hypot(i - io, j - jo);
  if (smn.size() < 4)
    smn.insert(d), smx.insert(d);
  else {
    if (d < *--smn.end()) smn.erase(--smn.end()), smn.insert(d);
    if (d > *smx.begin()) smx.erase(smx.begin()), smx.insert(d);
  }
  int kk, ii, jj;
  for (int lim = 0; lim < 4; ++lim, k = kk) {
    kk = (k + 1) % 4;
    ii = i + DX[kk];
    jj = j + DY[kk];
    if (valid(ii, jj) && (A[ii][jj] || AA[ii][jj])) {
      i = ii;
      j = jj;
      for (;;) {
        ii = i + DX[k];
        jj = j + DY[k];
        if (valid(ii, jj) && (A[ii][jj] || AA[ii][jj]))
          i = ii, j = jj;
        else
          break;
      }
      dfsd(i, j, k);
      return;
    }
  }
}
int main() {
  int i, j, k, ii, jj;
  char c;
  int a, d;
  for (i = (0); i < (15); ++i)
    for (j = (0); j < (15); ++j)
      O[i][j] = hypot(i - 15 / 2., j - 15 / 2.) <= 2 + 1e-9;
  np = nl = nr = 0;
  for (i = (0); i < (15); ++i)
    for (j = (0); j < (15); ++j)
      if (O[i][j]) {
        P[np++] = make_pair(i - 15 / 2, j - 15 / 2);
        if (O[i][j - 1] == 0) L[nl++] = make_pair(i - 15 / 2, j - 15 / 2);
        if (O[i][j + 1] == 0) R[nr++] = make_pair(i - 15 / 2, j - 15 / 2);
      }
  assert(nl == nr);
  int ts;
  for (ts = 1; scanf("%"
                     "d",
                     &(n)) > 0;
       ++ts) {
    for (i = (0); i < (n); ++i)
      for (j = (0); j < (n); ++j)
        scanf(
            "%"
            "d",
            &(a)),
            A[i][j] = a;
    for (i = (0); i < (n); ++i) {
      j = 0;
      m = 0;
      mm = 0;
      for (k = (0); k < (np); ++k) {
        ii = i + P[k].first;
        jj = j + P[k].second;
        if (valid(ii, jj)) ++m, mm += A[ii][jj];
      }
      AA[i][j] = mm > m / 2;
      for (j = (1); j < (n); ++j) {
        for (k = (0); k < (nl); ++k) {
          ii = i + L[k].first;
          jj = j - 1 + L[k].second;
          if (valid(ii, jj)) --m, mm -= A[ii][jj];
        }
        for (k = (0); k < (nr); ++k) {
          ii = i + R[k].first;
          jj = j + R[k].second;
          if (valid(ii, jj)) ++m, mm += A[ii][jj];
        }
        AA[i][j] = mm > m / 2;
      }
    }
    for (i = (0); i < (n); ++i)
      for (j = (0); j < (n); ++j) A[i][j] = AA[i][j];
    int res1 = 0, res2 = 0;
    for (i = (0); i < (n); ++i)
      for (j = (0); j < (n); ++j)
        if (AA[i][j] && A[i][j]) {
          pair<int, pair<int, int> > p = dfs(i, j);
          if (p.first > 88) {
            io = 1. * p.second.first / p.first;
            jo = 1. * p.second.second / p.first;
            smn.clear();
            smx.clear();
            dfsd(i, j, 0);
            if (2 * *smx.begin() > (1 + sqrt(2.)) * *--smn.end())
              ++res2;
            else
              ++res1;
          }
        }
    printf((firstout) ? "%"
                        "d"
                      : " %"
                        "d",
           (res1)),
        firstout = 0;
    printf((firstout) ? "%"
                        "d"
                      : " %"
                        "d",
           (res2)),
        firstout = 0;
    printf("\n"), firstout = 1;
  }
  return 0;
}
