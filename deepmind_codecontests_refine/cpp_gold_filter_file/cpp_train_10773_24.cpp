#include <bits/stdc++.h>
using namespace std;
template <class T>
void chmin(T &t, const T &f) {
  if (t > f) t = f;
}
template <class T>
void chmax(T &t, const T &f) {
  if (t < f) t = f;
}
char a[5005];
int gb[5005], ga[5005];
long long int ans[5005][5005] = {0};
long long int ret = 0;
int isNum(char a) {
  if (a - '0' >= 1 && a - '0' <= 9) return 1;
  return 0;
}
int main() {
  scanf("%s", a);
  long long int len = strlen(a);
  int gbb = -1;
  for (int i = 0; i < len; ++i) {
    if (a[i] - '0' >= 1 && a[i] - '0' <= 9)
      gb[i] = gbb;
    else if (a[i] == '+')
      gbb = i;
  }
  int gaa = (int)len;
  for (int i = (int)len - 1; i >= 0; --i) {
    if (a[i] - '0' >= 1 && a[i] - '0' <= 9)
      ga[i] = gaa;
    else if (a[i] == '+')
      gaa = i;
  }
  for (int i = 0; i < len; ++i) {
    if (a[i] - '0' < 1 || a[i] - '0' > 9) continue;
    long long int prev = 0, mul = 0;
    for (int j = i; j < len; ++j) {
      if (isNum(a[j])) {
        if (j == i) ans[i][j] = a[i] - '0';
        if (j - 1 >= 0 && j != i) {
          if (a[j - 1] == '*') {
            mul *= (a[j] - '0');
            ans[i][j] = prev + mul;
          } else
            ans[i][j] = prev + (a[j] - '0');
        }
      } else {
        if (a[j] == '*') {
          if (mul == 0) mul = a[j - 1] - '0';
        } else {
          if (mul > 0)
            prev += mul;
          else
            prev += a[j - 1] - '0';
          mul = 0;
        }
      }
    }
  }
  for (int i = 0; i < len; ++i) {
    if (!isNum(a[i])) continue;
    for (int j = i; j < len; ++j) {
      if (!isNum(a[j])) continue;
      long long int m = ans[i][j];
      int before = gb[i];
      if (i - 2 >= before + 1) m *= ans[before + 1][i - 2];
      int after = ga[j];
      if (j + 2 <= after - 1) m *= ans[j + 2][after - 1];
      if (before - 1 >= 0) m += ans[0][before - 1];
      if (after + 1 <= len - 1) m += ans[after + 1][len - 1];
      ret = max(ret, m);
    }
  }
  printf("%I64d", ret);
  return 0;
}
