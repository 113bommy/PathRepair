#include <bits/stdc++.h>
using namespace std;
int n;
struct point {
  long long x, y;
  bool operator<(point that) const { return x < that.x; }
} P[100001];
long long yMaxFromHead[100011];
long long yMinFromHead[100011];
long long yMaxFromTail[100011];
long long yMinFromTail[100011];
long long INF = 10000000000LL;
bool check(long long range) {
  int p = 1;
  for (int i = 1; i <= n; i++) {
    while (p + 1 <= n && P[p + 1].x - P[i].x <= range) p++;
    long long yMax = max(yMaxFromHead[i - 1], yMaxFromTail[p + 1]);
    long long yMin = min(yMinFromHead[i - 1], yMinFromTail[p + 1]);
    if (yMax - yMin <= range) {
      return true;
    }
  }
  return false;
}
int MAIN() {
  while (cin >> n) {
    for (int i = 1; i <= n; i++) {
      long long x, y;
      cin >> x >> y;
      P[i].x = x + y;
      P[i].y = x - y;
    }
    sort(P + 1, P + 1 + n);
    yMaxFromHead[0] = -INF;
    yMinFromHead[0] = +INF;
    for (int i = 1; i <= n; i++) {
      yMaxFromHead[i] = max(yMaxFromHead[i - 1], P[i].y);
      yMinFromHead[i] = min(yMinFromHead[i - 1], P[i].y);
    }
    yMaxFromTail[n + 1] = -INF;
    yMinFromTail[n + 1] = +INF;
    for (int i = n; i >= 1; i--) {
      yMaxFromTail[i] = max(yMaxFromTail[i + 1], P[i].y);
      yMinFromTail[i] = min(yMinFromTail[i + 1], P[i].y);
    }
    if (check(0))
      cout << 0 << endl;
    else {
      long long L = 0, R = 10000000000LL, M;
      while (R - L > 1) {
        M = (L + R) / 2;
        if (check(M))
          R = M;
        else
          L = M;
      }
      cout << double(R) / 2 << endl;
    }
  }
  return 0;
}
int main() {
  ios ::sync_with_stdio(false);
  cout << fixed << setprecision(16);
  return MAIN();
}
