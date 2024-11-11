#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f;
const double inf = 1e18;
const double eps = 1e-9;
const long long mod = 998244353;
const unsigned long long mx = 133333331;
inline void RI(int &x) {
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = (x << 3) + (x << 1) + c - '0';
}
int a[300010];
double p[3];
int n;
bool judge(double d) {
  int cnt = -1;
  int nt = 0;
  double k[3];
  for (int i = 1; i <= n; i++) {
    if (a[i] > cnt) {
      if (nt == 3) {
        return false;
      }
      k[nt++] = a[i] + d;
      cnt = a[i] + 2 * d;
    }
  }
  for (int i = nt; i < 3; i++) k[i] = 0;
  for (int i = 0; i < 3; i++) p[i] = k[i];
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1);
  double l = 0, r = 2e9 + 1;
  double ans = 0;
  int num = 200;
  while (r - l > 1e-7 && num != 0) {
    double m = (l + r) / 2.0;
    int res = judge(m);
    if (res == 1) {
      ans = m;
      r = m;
    } else
      l = m;
    num--;
  }
  printf("%.6f\n", ans);
  for (int i = 0; i < 3; i++) {
    printf("%.6f", p[i]);
    if (i == 2)
      printf("\n");
    else
      printf(" ");
  }
}
