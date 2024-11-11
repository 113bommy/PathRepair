#include <bits/stdc++.h>
using namespace std;
int n, m;
int tmpa[90001];
struct point {
  int a, th;
} line[90001];
int p[90001];
int seat[301][301];
bool cmp(point x, point y) {
  if (x.a < y.a) return true;
  if (x.a > y.a) return false;
  return x.th < y.th;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
      cin >> tmpa[i];
      line[i].a = tmpa[i];
      line[i].th = i;
    }
    sort(line + 1, line + n * m + 1, cmp);
    for (int i = 1; i <= n * m; i++) {
      p[line[i].th] = i;
    }
    for (int i = 1; i <= n; i++) {
      for (int t = 1; t <= m; t++) {
        seat[i][t] = line[(i - 1) * m + t].th;
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int t = 1; t <= m; t++) {
        for (int q = 1; q < t; q++)
          if (seat[i][q] < seat[i][t] && tmpa[seat[i][q]] != tmpa[seat[i][t]])
            ans++;
      }
    }
    cout << ans << endl;
  }
}
