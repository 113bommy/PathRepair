#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 10;
const double PI = acos(0.0) * 2;
const double eps = 1e-10;
const double STD = 0.999459;
const int dx[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
const double One = 0.5;
int n;
char s[N];
double a[N][N], b[N][N], coef[10][10];
bool vi[N][N];
pair<int, int> q[N * N];
template <class T>
T sqr(T x) {
  return x * x;
}
void GausscianBlur() {
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++) {
      b[i][j] = 0.0;
      for (int i1 = (i - 3); i1 <= (i + 3); i1++)
        if (i1 > 0 && i1 <= n)
          for (int j1 = (j - 3); j1 <= (j + 3); j1++)
            if (j1 > 0 && j1 <= n) {
              b[i][j] += a[i1][j1] * coef[abs(i - i1)][abs(j - j1)];
            }
    }
  memcpy(a, b, sizeof b);
}
void OutputGraph() {
  freopen("output.txt", "w", stdout);
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (n); j++)
      if (a[i][j] > One)
        printf("1");
      else
        printf("0");
    cout << endl;
  }
}
int CntCircle, CntSquare;
void solve(int x0, int y0) {
  int head = 1, tail = 1, xmin = x0, xmax = x0, ymin = y0, ymax = y0;
  q[1] = make_pair(x0, y0);
  vi[x0][y0] = 1;
  while (head <= tail) {
    int x = q[head].first, y = q[head].second;
    head++;
    xmin = min(xmin, x);
    xmax = max(xmax, x);
    ymin = min(ymin, y);
    ymax = max(ymax, y);
    for (int d = (0); d <= (3); d++) {
      int x1 = x + dx[d][0], y1 = y + dx[d][1];
      if (x1 < 1 || y1 < 1 || x1 > n || y1 > n || vi[x1][y1] || a[x1][y1] < One)
        continue;
      q[++tail] = make_pair(x1, y1);
      vi[x1][y1] = 1;
    }
  }
  if (tail < 150) return;
  double cx = (xmin + xmax) / 2.0, cy = (ymin + ymax) / 2.0, r = 0.0;
  for (int i = (1); i <= (tail); i++)
    r = max(r, sqrt(sqr(cx - q[i].first) + sqr(cy - q[i].second)));
  double P = tail / r / r;
  if (P < 2.5)
    CntSquare++;
  else
    CntCircle++;
}
int main() {
  for (int i = (0); i <= (9); i++)
    for (int j = (0); j <= (9); j++)
      coef[i][j] = exp(-0.5 * (sqr(i) + sqr(j))) / 2 / PI / STD;
  cin >> n;
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++) {
      char ch;
      do {
        ch = getchar();
      } while (ch != '0' && ch != '1');
      a[i][j] = (ch == '1') ? 1.0 : 0.0;
    }
  for (int _ = (1); _ <= (1); _++) GausscianBlur();
  for (int i = (1); i <= (n); i++)
    for (int j = (1); j <= (n); j++)
      if (!vi[i][j] && a[i][j] > One - eps) solve(i, j);
  cout << CntCircle << " " << CntSquare << endl;
  return 0;
}
