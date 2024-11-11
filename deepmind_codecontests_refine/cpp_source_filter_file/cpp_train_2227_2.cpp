#include <bits/stdc++.h>
using namespace std;
void RD(int &x) { scanf("%d", &x); }
void RD(long long &x) { scanf("%I64d", &x); }
void RD(unsigned long long &x) { scanf("%I64u", &x); }
void RD(unsigned int &x) { scanf("%u", &x); }
void RD(double &x) { scanf("%lf", &x); }
void RD(int &x, int &y) { scanf("%d%d", &x, &y); }
void RD(long long &x, long long &y) { scanf("%I64d%I64d", &x, &y); }
void RD(unsigned int &x, unsigned int &y) { scanf("%u%u", &x, &y); }
void RD(double &x, double &y) { scanf("%lf%lf", &x, &y); }
void RD(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void RD(long long &x, long long &y, long long &z) {
  scanf("%I64d%I64d%I64d", &x, &y, &z);
}
void RD(unsigned int &x, unsigned int &y, unsigned int &z) {
  scanf("%u%u%u", &x, &y, &z);
}
void RD(double &x, double &y, double &z) { scanf("%lf%lf%lf", &x, &y, &z); }
void RD(char &x) { x = getchar(); }
void RD(char *s) { scanf("%s", s); }
void RD(string &s) { cin >> s; }
void PR(int x) { printf("%d\n", x); }
void PR(int x, int y) { printf("%d %d\n", x, y); }
void PR(long long x) { printf("%I64d\n", x); }
void PR(unsigned int x) { printf("%u\n", x); }
void PR(unsigned long long x) { printf("%I64u\n", x); }
void PR(double x) { printf("%.6lf\n", x); }
void PR(char x) { printf("%c\n", x); }
void PR(char *x) { printf("%s\n", x); }
void PR(string x) { cout << x << endl; }
const int mod = 10007;
const long long inf = ((long long)1) << 60;
const double dinf = 1e50;
const int INF = 2000000005;
const int N = 100005;
pair<int, int> a[N];
int n;
int preMin[N], preMax[N], sufMin[N], sufMax[N];
int OK(long long d) {
  int i, j = 1, y1, y2;
  for (i = 1; i <= n; i++) {
    while (a[i].first > a[j].first + d) j++;
    y1 =
        ((sufMax[i + 1]) > (preMax[j - 1]) ? (sufMax[i + 1]) : (preMax[j - 1]));
    y2 =
        ((sufMin[i + 1]) < (preMin[j - 1]) ? (sufMin[i + 1]) : (preMin[j - 1]));
    if (y1 - y2 <= d) return 1;
  }
  return 0;
}
int main() {
  RD(n);
  int i, x, y;
  for (i = 1; i <= n; i++) {
    RD(x, y);
    a[i] = make_pair(x - y, x + y);
  }
  sort(a, a + n);
  preMin[0] = INF;
  preMax[0] = -INF;
  for (i = 1; i <= n; i++) {
    preMin[i] =
        ((preMin[i - 1]) < (a[i].second) ? (preMin[i - 1]) : (a[i].second));
    preMax[i] =
        ((preMax[i - 1]) > (a[i].second) ? (preMax[i - 1]) : (a[i].second));
  }
  sufMin[n + 1] = INF;
  sufMax[n + 1] = -INF;
  for (i = n; i >= 1; i--) {
    sufMin[i] =
        ((sufMin[i + 1]) < (a[i].second) ? (sufMin[i + 1]) : (a[i].second));
    sufMax[i] =
        ((sufMax[i + 1]) > (a[i].second) ? (sufMax[i + 1]) : (a[i].second));
  }
  long long low = 0, high = inf, mid, ans;
  while (low <= high) {
    mid = (low + high) >> 1;
    if (OK(mid))
      ans = mid, high = mid - 1;
    else
      low = mid + 1;
  }
  PR(ans / 2.0);
  return 0;
}
