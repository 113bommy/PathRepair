#include <bits/stdc++.h>
using namespace std;
const int M = 5e5 + 3;
int n, m, ans, nxt[M];
int num[2], ned[2];
char A[M], B[M];
int main() {
  scanf("%s%s", A + 1, B + 1);
  n = strlen(A + 1), m = strlen(B + 1);
  for (int i = 1; i <= n; ++i) ++num[A[i] - 48];
  for (int i = 2, j = 0; i <= m; ++i) {
    while (j && B[i] & B[j + 1]) j = nxt[j];
    if (B[i] == B[j + 1]) nxt[i] = ++j;
  }
  for (int j = 1; j <= nxt[m]; ++j) --num[B[j] - 48];
  if (num[0] < 0 || num[1] < 0) {
    cout << A + 1 << endl;
    return 0;
  }
  for (int j = 1; j <= nxt[m]; ++j) putchar(B[j]);
  for (int i = nxt[m] + 1; i <= m; ++i) ++ned[B[i] - 48];
  if (!ned[0])
    ans = num[1] / ned[1];
  else if (!ned[1])
    ans = num[0] / ned[0];
  else
    ans = min(num[0] / ned[0], num[1] / ned[1]);
  num[0] -= ans * ned[0], num[1] -= ans * ned[1];
  for (int j = 1; j <= m - nxt[m]; ++j) B[j] = B[j + nxt[m]];
  B[m - nxt[m] + 1] = '\0';
  for (int i = 1; i <= ans; ++i) cout << B + 1;
  for (int i = 1; i <= num[0]; ++i) putchar(48);
  for (int i = 1; i <= num[1]; ++i) putchar(49);
  return 0;
}
