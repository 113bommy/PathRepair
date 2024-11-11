#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
typedef struct {
  double x;
  double a;
} fangzi;
fangzi f[N];
bool cmp(fangzi c, fangzi d) { return c.x < d.x; }
int main() {
  ios::sync_with_stdio(false);
  int n;
  double t;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> f[i].x >> f[i].a;
  }
  sort(f, f + n, cmp);
  int cnt = 2;
  double t1, t2;
  for (int i = 1; i < n; i++) {
    t1 = f[i].x - f[i].a / 2;
    t2 = f[i - 1].x + f[i - 1].a / 2;
    if (t1 - t2 > t)
      cnt += 2;
    else if (t1 - t2 == t)
      cnt++;
  }
  cout << cnt << endl;
  return 0;
}
