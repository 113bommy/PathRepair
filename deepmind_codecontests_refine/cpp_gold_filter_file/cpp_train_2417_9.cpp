#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-13;
const long double pi = 3.14159265358979323846264L;
const int N = 2505;
int t, n, tn;
struct Point {
  long double x, y;
  void read() { cin >> x >> y; }
} p[N];
long double r[2 * N];
long long C(int n, int m) {
  if (m > n) return 0;
  long long ans = 1;
  for (int i = 0; i < m; i++) ans = ans * (n - i) / (i + 1);
  return ans;
}
long double cal(Point a, Point b) { return atan2(b.y - a.y, b.x - a.x); }
long long solve(int num) {
  tn = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == num) continue;
    r[tn++] = cal(p[num], p[i]);
  }
  sort(r, r + tn);
  int j = 1;
  for (int i = 0; i < tn; i++) r[i + tn] = r[i] + 2 * pi;
  for (int i = 0; i < tn; i++) {
    if (j < i) j = i;
    while (j < tn * 2 && r[j] - r[i] - pi < 0) j++;
    ans += C(j - i - 1, 2);
  }
  return C(tn, 3) - ans;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) p[i].read();
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += solve(i);
  }
  cout << ans * (n - 4) / 2 << endl;
  return 0;
}
