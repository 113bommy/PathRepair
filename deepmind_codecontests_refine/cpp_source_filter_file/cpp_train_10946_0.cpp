#include <bits/stdc++.h>
using namespace std;
int dx[] = {+1, -1, +0, +0};
int dy[] = {+0, +0, +1, -1};
int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1};
int hr[] = {-2, -2, -1, +1, +2, +2, -1, +1};
int hc[] = {+1, -1, +2, +2, -1, +1, -2, -2};
const int MAXN = (int)1e5 + 9;
int main() {
  long long i, j, k, l, m, n, p, q, x, y, u, v, r, tc, t;
  long long a, b, c;
  cin >> a >> b >> c;
  p = a;
  q = b;
  r = c;
  long long F[8] = {0, 0, 1, 2, 2, 2, 3, 3};
  long long R[8] = {0, 1, 1, 1, 2, 2, 2, 2};
  long long C[8] = {0, 0, 0, 0, 0, 1, 1, 2};
  long long ans = 0;
  for (i = 1; i <= 7; i++) {
    long long ret1, ret2, ret3;
    ret1 = 0;
    for (j = i; j <= 7; j++) {
      if (F[j] - F[i - 1] > a) break;
    }
    j--;
    ret1 += j - i + 1;
    a -= F[j] - F[i - 1];
    if (a > 0) {
      ret1 += 7 * (a / 3);
      a %= 3;
      for (j = 1; j <= 7; j++) {
        if (F[j] > a) break;
      }
      j--;
      ret1 += j;
      a -= F[j];
    }
    if (j == 3) ret1 += 2;
    if (j == 4) ret1++;
    if (j == 6) ret1 += 2;
    if (j == 7) ret1++;
    ret2 = 0;
    for (j = i; j <= 7; j++) {
      if (R[j] - R[i - 1] > b) break;
    }
    j--;
    ret2 += j - i + 1;
    b -= R[j] - R[i - 1];
    if (b > 0) {
      ret2 += 7 * (b / 2);
      b %= 2;
      for (j = 1; j <= 7; j++) {
        if (R[j] > b) break;
      }
      j--;
      ret2 += j;
      b -= R[j];
    }
    if (j == 1) ret2 += 2;
    if (j == 2) ret2++;
    if (j == 4) ret2 += 2;
    ret3 = 0;
    for (j = i; j <= 7; j++) {
      if (C[j] - C[i - 1] > c) break;
    }
    j--;
    ret3 += j - i + 1;
    c -= C[j] - C[i - 1];
    if (c > 0) {
      ret3 += 7 * (c / 2);
      c %= 2;
      for (j = 1; j <= 7; j++) {
        if (C[j] > c) break;
      }
      j--;
      ret3 += j;
      c -= C[j];
    }
    if (j == 1) ret3 += 3;
    if (j == 2) ret3 += 2;
    if (j == 3) ret3 += 1;
    if (j == 5) ret3++;
    if (j == 7) ret3++;
    long long ret = min(ret1, min(ret2, ret3));
    ans = max(ans, ret);
    a = p;
    b = q;
    c = r;
  }
  cout << ans << endl;
  return 0;
}
