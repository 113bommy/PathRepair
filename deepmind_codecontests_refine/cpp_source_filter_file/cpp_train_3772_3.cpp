#include <bits/stdc++.h>
using namespace std;
const int N = 100001, offset = 100000;
int n, m, s[9];
pair<int, int> r[N], c[N], x[N * 2], y[N * 2], d[N];
int main() {
  cin >> n >> m;
  for (int i = 0; i < N; i++) {
    r[i] = {N, -1};
    c[i] = {N, -1};
  }
  for (int i = 0; i < 2 * N; i++) {
    x[i] = {N, -1};
    y[i] = {N, -1};
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    d[i] = {a, b};
    r[a].first = min(b, r[a].first);
    r[a].second = max(b, r[a].second);
    c[b].first = min(a, c[b].first);
    c[b].second = max(a, c[b].second);
    x[a - b + offset].first = min(x[a - b + offset].first, a);
    x[a - b + offset].second = max(x[a - b + offset].second, a);
    x[a + b].first = min(x[a + b].first, a);
    x[a + b].second = max(x[a + b].second, a);
  }
  for (int i = 0; i < m; i++) {
    int a = d[i].first, b = d[i].second, k = 0;
    if (b > r[a].first) k++;
    if (b < r[a].second) k++;
    if (a > c[b].first) k++;
    if (a < c[b].second) k++;
    if (a > x[a - b + offset].first) k++;
    if (a < x[a - b + offset].second) k++;
    if (a > x[a + b].first) k++;
    if (a < x[a + b].second) k++;
    s[k]++;
  }
  for (int i = 0; i < 9; i++) cout << s[i] << " ";
}
