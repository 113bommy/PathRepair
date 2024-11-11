#include <bits/stdc++.h>
using namespace std;
int n, m;
int i, j, k, l;
int a[1111][1111], K;
long long sl[1111][1111], sr[1111][1111];
long long s[1111][1111];
inline long long sq(int x1, int stupid_cmath, int x2, int y2) {
  return s[x1][stupid_cmath] - s[x1][y2 + 1] - s[x2 + 1][stupid_cmath] +
         s[x2 + 1][y2 + 1];
}
long long f(int x, int y) {
  long long s = 0;
  int i, j;
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) {
      s += ((0) > (K - ((i - x) < 0 ? -(i - x) : (i - x)) -
                   ((j - y) < 0 ? -(j - y) : (j - y)))
                ? (0)
                : (K - ((i - x) < 0 ? -(i - x) : (i - x)) -
                   ((j - y) < 0 ? -(j - y) : (j - y)))) *
           a[i][j];
    }
  return s;
}
int main() {
  scanf("%d%d%d", &n, &m, &K);
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) scanf("%d", &a[i][j]);
  if (K == 1) {
    k = l = 0;
    for (i = 0; i < n; ++i)
      for (j = 0; j < m; ++j)
        if (a[i][j] > a[l][k]) k = j, l = i;
    cout << k + 1 << ' ' << l + 1 << endl;
    return 0;
  }
  for (i = n + 1; i >= 0; --i)
    for (j = m + 1; j >= 0; --j)
      s[i][j] = s[i + 1][j] + s[i][j + 1] + a[i][j] - s[i + 1][j + 1];
  for (i = n + 1; i >= 0; --i)
    for (j = m + 1; j >= 0; --j) sr[i][j] = a[i][j] + sr[i + 1][j + 1];
  for (i = n + 1; i >= 0; --i)
    for (j = 0; j <= m + 1; ++j) sl[i][j] = a[i][j] + sl[i + 1][j - 1];
  long long S = 0, R = 0, L = 0, U = 0, D = 0;
  int x = K - 1, y = K - 1;
  long long fmx = 0;
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) {
      S += ((0) > (K - ((i - x) < 0 ? -(i - x) : (i - x)) -
                   ((j - y) < 0 ? -(j - y) : (j - y)))
                ? (0)
                : (K - ((i - x) < 0 ? -(i - x) : (i - x)) -
                   ((j - y) < 0 ? -(j - y) : (j - y)))) *
           a[i][j];
      L += (((i - x) < 0 ? -(i - x) : (i - x)) +
                ((j - y) < 0 ? -(j - y) : (j - y)) <
            K) *
           a[i][j] * (j <= y);
      R += (((i - x) < 0 ? -(i - x) : (i - x)) +
                ((j - y) < 0 ? -(j - y) : (j - y)) <=
            K) *
           a[i][j] * (j > y);
      U += (((i - x) < 0 ? -(i - x) : (i - x)) +
                ((j - y) < 0 ? -(j - y) : (j - y)) <
            K) *
           a[i][j] * (i <= x);
      D += (((i - x) < 0 ? -(i - x) : (i - x)) +
                ((j - y) < 0 ? -(j - y) : (j - y)) <=
            K) *
           a[i][j] * (i > x);
    }
  for (i = K - 1; i <= n - K; ++i) {
    long long ST = S;
    long long LT = L;
    long long RT = R;
    for (j = K - 1; j <= m - K; ++j) {
      if (fmx < S) {
        fmx = S;
        x = i;
        y = j;
      }
      if (j == m - K) break;
      S = S - L + R;
      R -= sq(i - K + 1, j + 1, i + K - 1, j + 1);
      R += sr[i - K + 1][j + 2] - sr[i][j + K + 1];
      R += sl[i][j + K + 1] - sl[i + K][j + 1];
      L += sq(i - K + 1, j + 1, i + K - 1, j + 1);
      L -= sl[i - K + 1][j] - sl[i][j - K + 1];
      L -= sr[i][j - K + 1] - sr[i + K][j + 1];
    }
    S = ST;
    L = LT;
    R = RT;
    if (i == n - K) break;
    j = K - 1;
    S = S - U + D;
    U += sq(i + 1, j - K + 1, i + 1, j + K - 1);
    U -= sl[i - K + 1][j] - sl[i + 1][j - K];
    U -= sr[i - K + 2][j + 1] - sr[i + 1][j + K];
    D -= sq(i + 1, j - K + 1, i + 1, j + K - 1);
    D += sr[i + 2][j - K + 1] - sr[i + K + 1][j];
    D += sl[i + 2][j + K - 1] - sl[i + K + 2][j - 1];
    L -= sl[i - K + 1][j] - sl[i + 1][j - K];
    L += sr[i + 1][j - K + 1] - sr[i + K + 1][j + 1];
    R -= sr[i - K + 1][j + 1] - sr[i + 1][j + K + 1];
    R += sl[i + 1][j + K] - sl[i + K + 1][j];
  }
  cout << x + 1 << ' ' << y + 1 << endl;
  return 0;
}
