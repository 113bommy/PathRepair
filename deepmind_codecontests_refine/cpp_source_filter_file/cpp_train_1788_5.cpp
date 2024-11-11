#include <bits/stdc++.h>
using namespace std;
template <class T>
bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}
const int MX = 1010;
int n, m, q;
int arr[MX][MX];
int pref[MX][MX];
long long getsum(int ilo, int ihi, int jlo, int jhi) {
  long long res = pref[ihi][jhi];
  if (ilo > 0) res -= pref[ilo - 1][jhi];
  if (jlo > 0) res -= pref[ihi][jlo - 1];
  if (ilo > 0 && jlo > 0) res += pref[ilo - 1][jlo - 1];
  return res;
}
long long getinvsum(int ilo, int ihi, int jlo, int jhi) {
  long long res = getsum(ilo, ihi, jlo, jhi);
  res = (ihi - ilo + 1) * (jhi - jlo + 1) - res;
  return res;
}
char getLetter(long long i, long long j, long long val) {
  if (i < 2 && j < 2) {
    if ((i + j) % 2 == 0) return 'a';
    return 'b';
  }
  if (val == -1) {
    val = 1;
    while (val <= i || val <= j) val *= 2LL;
  }
  long long newi = i % (val / 2);
  long long newj = j % (val / 2);
  int cnt = 0;
  if (i >= val / 2) cnt ^= 1;
  if (j >= val / 2) cnt ^= 1;
  if (cnt) return 'a' + ('b' - getLetter(newi, newj, val / 2));
  return getLetter(newi, newj, val / 2);
}
long long getpref(long long i, long long j) {
  long long normalTot = getsum(0, n - 1, 0, m - 1);
  long long invTot = getinvsum(0, n - 1, 0, m - 1);
  long long res = 0;
  long long numSquaresI = (i + 1) / (2 * n);
  long long numSquaresJ = (j + 1) / (2 * m);
  res += numSquaresI * numSquaresJ * (2 * normalTot + 2 * invTot);
  if (i % (2 * n) != 2 * n - 1) {
    long long aSum = getsum(0, i % n, 0, m - 1);
    long long bSum = getinvsum(0, i % n, 0, m - 1);
    if (i % (2 * n) >= n) {
      aSum = normalTot + getinvsum(0, i % n, 0, m - 1);
      bSum = invTot + getsum(0, i % n, 0, m - 1);
    }
    res += numSquaresJ * (aSum + bSum);
  }
  if (j % (2 * m) != 2 * m - 1) {
    long long aSum = getsum(0, n - 1, 0, j % m);
    long long bSum = getinvsum(0, n - 1, 0, j % m);
    if (j % (2 * m) >= m) {
      aSum = normalTot + getinvsum(0, n - 1, 0, j % m);
      bSum = invTot + getsum(0, n - 1, 0, j % m);
    }
    res += numSquaresI * (aSum + bSum);
  };
  ;
  if (i % (2 * n) != 2 * n - 1 && j % (2 * m) != 2 * m - 1) {
    long long ci = i % (2 * n);
    long long cj = j % (2 * m);
    if (getLetter(numSquaresI * 2, numSquaresJ * 2, -1) == 'a') {
      if (ci < n && cj < m) {
        res += getsum(0, ci, 0, cj);
      } else if (n <= ci && ci < 2 * n && cj < m) {
        res += getsum(0, n - 1, 0, cj) + getinvsum(0, ci % n, 0, cj);
      } else if (ci < n && m <= cj && cj < 2 * m) {
        res += getsum(0, ci, 0, m - 1) + getinvsum(0, ci, 0, cj % m);
      } else {
        res += normalTot + getinvsum(0, ci % n, 0, m - 1) +
               getinvsum(0, n - 1, 0, cj % m) + getsum(0, ci % n, 0, cj % m);
      }
    } else {
      if (ci < n && cj < m) {
        res += getinvsum(0, ci, 0, cj);
      } else if (n <= ci && ci < 2 * n && cj < m) {
        res += getinvsum(0, n - 1, 0, cj) + getsum(0, ci % n, 0, cj);
      } else if (ci < n && m <= cj && cj < 2 * m) {
        res += getinvsum(0, ci, 0, m - 1) + getsum(0, ci, 0, cj % m);
      } else {
        res += normalTot + getsum(0, ci % n, 0, m - 1) +
               getsum(0, n - 1, 0, cj % m) + getinvsum(0, ci % n, 0, cj % m);
      }
    }
  };
  return res;
}
long long getBigSum(long long ilo, long long ihi, long long jlo,
                    long long jhi) {
  long long res = getpref(ihi, jhi);
  if (ilo > 0) res -= getpref(ilo - 1, jhi);
  if (jlo > 0) res -= getpref(ihi, jlo - 1);
  if (ilo > 0 && jlo > 0) res += getpref(ilo - 1, jlo - 1);
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    string second;
    cin >> second;
    for (int j = 0; j < m; j++) arr[i][j] = (second[j] == '1');
  }
  for (int i = 0; i < n; i++) {
    pref[i][0] = arr[i][0];
    for (int j = 1; j < m; j++) pref[i][j] = pref[i][j - 1] + arr[i][j];
  }
  for (int j = 0; j < m; j++) {
    for (int i = 1; i < n; i++) pref[i][j] += pref[i - 1][j];
  }
  while (q--) {
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    cout << getBigSum(x1, x2, y1, y2) << "\n";
  }
}
