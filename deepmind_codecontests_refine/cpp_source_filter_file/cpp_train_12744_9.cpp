#include <bits/stdc++.h>
using namespace std;
void RD(int &x) { scanf("%d", &x); }
void RD(double &x) { scanf("%lf", &x); }
void RD(int &x, int &y) { scanf("%d%d", &x, &y); }
void RD(double &x, double &y) { scanf("%lf%lf", &x, &y); }
void RD(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void RD(double &x, double &y, double &z) { scanf("%lf%lf%lf", &x, &y, &z); }
void RD(char *s) { scanf("%s", s); }
void PR(int x) { printf("%d\n", x); }
void PR(int x, int y) { printf("%d %d\n", x, y); }
void PR(double x) { printf("%.6lf\n", x); }
void PR(char x) { printf("%c\n", x); }
void PR(char x[]) { printf("%s\n", x); }
void PRI(char x[]) { printf("%s", x); }
char mp[5001][5001];
int right2[5001][5001];
int main() {
  int n, m;
  RD(n, m);
  int i, j;
  for (i = 0; i < (n); ++i) RD(mp[i]);
  memset((right2), 0, sizeof((right2)));
  for (i = 0; i < (n); ++i)
    for (j = (m - 1); j >= (0); --j) {
      if (mp[i][j] == '0')
        right2[i][j] = 0;
      else {
        if (j < n - 1)
          right2[i][j] = right2[i][j + 1] + 1;
        else
          right2[i][j] = 1;
      }
    }
  for (i = 0; i < (5000); ++i)
    for (j = (i + 1); j <= (5000); ++j) {
      int tmp;
      tmp = right2[i][j];
      right2[i][j] = right2[j][i];
      right2[j][i] = tmp;
    }
  for (i = 0; i < (m); ++i) sort(right2[i], right2[i] + n);
  int ans = 0;
  for (i = 0; i < (m); ++i)
    for (j = 0; j < (n); ++j) {
      if (right2[i][j] * (n - j) > ans) {
        ans = right2[i][j] * (n - j);
      }
    }
  PR(ans);
  return 0;
}
