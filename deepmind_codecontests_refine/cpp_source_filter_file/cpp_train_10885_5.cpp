#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
long long int getint() {
  long long int ans = 0;
  int f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') f = -f;
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = getchar();
  }
  return ans * f;
}
using namespace std;
const int MAXN = 1000;
char s[MAXN + 10];
int len;
int getnum(int &i, int &l) {
  int ret = 0;
  while (i <= len && s[i] >= '0' && s[i] <= '9') {
    ret = ret * 10 + s[i] - '0';
    ++l;
    ++i;
  }
  return ret;
}
int num[MAXN + 10];
int main() {
  scanf("%s", s + 1);
  len = strlen(s + 1);
  double ans = 0;
  for (int i = 1; i <= len; ++i) {
    while (i <= len && s[i] >= 'a' && s[i] <= 'z') ++i;
    if (i > len) break;
    double ts = 0;
    while (1) {
      int l = 0;
      int k = getnum(i, l);
      if (l == 2 && s[i] != '.') {
        ts += k * 1.0 / 100;
        --i;
        break;
      } else {
        ts = ts * 1000 + k;
        if (i > len || s[i] != '.') {
          --i;
          break;
        } else
          ++i;
      }
    }
    ans += ts;
  }
  num[0] = (int)((ans - (int)ans) * 100 + 0.001);
  int n = (int)ans, k = 0;
  while (n) {
    num[++k] = n % 1000;
    n /= 1000;
  }
  if (!k) {
    printf("%.2lf\n", 1.0 * num[0] / 100);
    return 0;
  } else {
    printf("%d", num[k]);
    for (int i = k - 1; i > 0; --i) printf(".%03d", num[i]);
    if (num[0]) printf(".%d\n", num[0]);
  }
  return 0;
}
