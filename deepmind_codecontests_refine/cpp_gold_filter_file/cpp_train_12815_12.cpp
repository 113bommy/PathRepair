#include <bits/stdc++.h>
using namespace std;
int l;
struct Mat {
  long long v[45][45] = {};
  Mat friend operator*(Mat x1, Mat x2) {
    Mat x3;
    for (int i = 0; i < l; i++)
      for (int k = 0; k < l; k++)
        for (int j = 0; j < l; j++) x3.v[i][j] += x1.v[i][k] * x2.v[k][j];
    return x3;
  }
};
char s[105];
bool ok(int l1, int l2) {
  if (l1) {
    if (s[l1] == s[l2 + 1]) return 0;
    for (int i = l1 - 1, j = l2; i > 0; i--, j--) {
      if (s[i] != s[j]) return 0;
    }
  }
  return 1;
}
Mat pows(Mat x, int y) {
  Mat ans;
  for (int i = 0; i < l; i++) ans.v[i][i] = 1;
  while (y) {
    if (y % 2) ans = x * ans;
    x = x * x;
    y >>= 1;
  }
  return ans;
}
int main() {
  int n;
  long long ans;
  Mat a;
  scanf("%d", &n);
  scanf("%s", s + 1);
  l = strlen(s + 1);
  ans = 1LL << n;
  for (int i = 0; i < l; i++) {
    if (i + 1 < l) a.v[i][i + 1] = 1;
    for (int j = i; j >= 0; j--) {
      if (ok(j, i)) {
        a.v[i][j] = 1;
        break;
      }
    }
  }
  a = pows(a, n);
  for (int i = 0; i < l; i++) ans -= a.v[i][i];
  printf("%lld\n", ans);
  return 0;
}
