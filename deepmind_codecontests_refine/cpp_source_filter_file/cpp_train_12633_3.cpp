#include <bits/stdc++.h>
using namespace std;
complex<double> p[1000];
int ans[2000];
int len, N, n;
const double pi = acos(-1.0);
const double sd = cos(36.0 / 180 * pi) * 10 * 2;
const double ag = 2 * asin(5 / sd);
struct pol {
  int p[5];
} num[200];
void dfs(int tp, const complex<double>& s) {
  if (tp == n) return;
  num[tp].p[0] = tp;
  p[len] = complex<double>(real(s) + sd, imag(s));
  num[tp].p[1] = len;
  ans[N++] = len++;
  dfs(tp + 1, p[len - 1]);
  p[len] = complex<double>(real(p[len - 1]) - cos(ag) * sd,
                           imag(p[len - 1]) - sin(ag) * sd);
  num[tp].p[2] = len;
  ans[N++] = len++;
  p[len] = complex<double>(real(p[len - 1]) + sin(ag / 2) * sd,
                           imag(p[len - 1]) + cos(ag / 2) * sd);
  num[tp].p[3] = len;
  ans[N++] = len++;
  p[len] = complex<double>(real(p[len - 1]) + sin(ag / 2) * sd,
                           imag(p[len - 1]) - cos(ag / 2) * sd);
  num[tp].p[4] = len;
  ans[N++] = len++;
  ans[N++] = tp;
}
int main() {
  ans[0] = 0;
  p[0] = complex<double>(0, 0);
  while (cin >> n) {
    N = len = 1;
    dfs(0, p[0]);
    cout << len << endl;
    for (int i = 0; i < len; i++)
      printf("%.11lf %.11lf\n", real(p[i]), imag(p[i]));
    for (int i = 0; i < n; i++) {
      int* p = num[i].p;
      for (int j = 0; j < 5; j++) num[i].p[j]++;
      cout << p[0] << " " << p[3] << " " << p[1] << " " << p[4] << " " << p[2]
           << endl;
    }
    for (int i = 0; i < N; i++) cout << ans[i] + 1 << " ";
    cout << endl;
  }
}
