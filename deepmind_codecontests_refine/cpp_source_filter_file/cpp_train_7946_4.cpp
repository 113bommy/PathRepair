#include <bits/stdc++.h>
using namespace std;
int n;
double t1, a, t2, b, x1, x2, k;
pair<int, double> s[10005];
bool cmp(pair<int, double> a, pair<int, double> b) {
  if (a.second > b.second) return 1;
  if (a.second == b.second) {
    if (a.first > b.second) return 1;
  }
  return 0;
}
int main() {
  cin >> n >> t1 >> t2 >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    x1 = 0, x2 = 0;
    x1 = a * t1;
    x2 = b * t1;
    x1 = x1 - (x1 * k / 100);
    x2 = x2 - (x2 * k / 100);
    x1 += b * t2;
    x2 += a * t2;
    s[i] = {i, max(x1, x2)};
  }
  sort(s + 1, s + 1 + n, &cmp);
  for (int i = 1; i <= n; i++) {
    cout << s[i].first << " ";
    cout.precision(2);
    cout << fixed << s[i].second << "\n";
  }
}
