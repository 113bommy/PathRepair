#include <bits/stdc++.h>
using namespace std;
const int MAXN = 101 * 1001;
double g = 9.8;
pair<double, double> ans[MAXN], wall[MAXN];
pair<double, int> angle[MAXN];
inline double cot(double x) { return sin(x) / cos(x); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  double v;
  cin >> n >> v;
  for (int i = 0; i < n; i++) cin >> angle[i].first, angle[i].second = i;
  sort(angle, angle + n);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) cin >> wall[i].first >> wall[i].second;
  sort(wall, wall + m);
  int j = 0;
  for (int i = 0; i < n; i++) {
    double alp = angle[i].first, x = wall[j].first;
    while (j < m &&
           x * cot(alp) - g * x * x / (2 * v * v * cos(alp) * cos(alp)) >=
               wall[j].second) {
      j++;
      x = wall[j].first;
    }
    if (j == m || wall[j].first > 2.0 * (sin(alp) * cos(alp) * v * v) / g) {
      ans[angle[i].second] = {2.0 * (sin(alp) * cos(alp) * v * v) / g, 0};
    } else
      ans[angle[i].second] = {
          x, x * cot(alp) - g * x * x / (2 * v * v * cos(alp) * cos(alp))};
    j -= 2;
    j = max(0, j);
  }
  for (int i = 0; i < n; i++)
    cout << ans[i].first << ' ' << ans[i].second << '\n';
}
