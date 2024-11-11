#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const double pi = acos(-1);
const int SLMT = 1e5 + 5;
const int ALMT = 1e6 + 5;
template <class T>
inline void sd(T &num) {
  num = 0;
  int sign = 0;
  char ch;
  while (isspace(ch = getchar()))
    ;
  if (isdigit(ch))
    num = ch - '0';
  else
    sign = ch == '+' ? 0 : 1;
  while (isdigit(ch = getchar())) num = (num << 3) + (num << 1) + ch - '0';
  num = sign ? -num : num;
}
template <class T>
inline void pd(T num, char ch = ' ') {
  if (num < 0) {
    putchar('-');
    num = -num;
  }
  char digits[21] = {};
  int pos = 1;
  do {
    digits[pos++] = '0' + num % 10;
  } while (num /= 10);
  while (--pos) putchar(digits[pos]);
  putchar(ch);
}
template <class T>
inline void iArr(T &arr, int size) {
  for (auto i = 0; i != size; ++i) sd(arr[i]);
}
template <class T>
inline int mArr(T &arr, int size) {
  int val;
  int mval = INT_MIN;
  for (auto i = 0; i != size; ++i) sd(val), ++arr[val], mval = max(mval, val);
  return mval;
}
template <class T>
inline void oArr(T &arr, int size) {
  for (auto i = 0; i != size; ++i) pd(arr[i]);
  putchar('\n');
}
template <class T>
inline void iMat(T &mat, int n, int m) {
  for (auto i = 0; i != n; ++i)
    for (auto j = 0; j != m; ++j) sd(mat[i][j]);
}
template <class T>
inline void oMat(T &mat, int n, int m) {
  for (auto i = 0; i != n; ++i) {
    for (auto j = 0; j != m; ++j) pd(mat[i][j]);
    putchar('\n');
  }
}
inline void oMat(char **mat, int n) {
  for (auto i = 0; i != n; ++i) puts(mat[i]);
}
inline void iMat(char **mat, int n) {
  for (auto i = 0; i != n; ++i) scanf("%s", mat[i]);
}
template <class T>
inline void MAT(T **&mat, int r, int c, T val = 0) {
  mat = new T *[r];
  if (!val) {
    for (auto i = 0; i != r; ++i) mat[i] = new T[c]();
    return;
  }
  for (auto i = 0; i != r; ++i) {
    mat[i] = new T[c];
    for (auto j = 0; j != c; ++j) mat[i][j] = val;
  }
}
template <class T>
inline void ARR(T *&arr, int n, int val = 0) {
  arr = new T[n];
  fill(arr, arr + n, val);
}
int bug = 0;
const int MLEN = 5e3 + 1;
const int MOD = 1e9 + 7;
char s1[MLEN], s2[MLEN];
int dp[MLEN][MLEN];
int main(void) {
  scanf("%s", s1);
  scanf("%s", s2);
  int len1 = strlen(s1);
  int len2 = strlen(s2);
  for (auto i = len1 - 1; i != -1; --i)
    for (auto j = len2 - 1; j != -1; --j)
      dp[i][j] =
          dp[i][j + 1] + (s1[i] == s2[j] ? 1 + dp[i + 1][j + 1] : 0) % MOD;
  int ans = 0;
  for (int i = 0; i < len1; ++i) (ans += dp[i][0]) %= MOD;
  pd(ans);
  return 0;
}
