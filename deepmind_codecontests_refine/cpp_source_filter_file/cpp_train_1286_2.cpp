#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
vector<int> a, b;
int n, x, mv = INF;
int main() {
  cin >> n >> x;
  a.resize(n);
  b.resize(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int p1 = 0, p2 = n;
  while (p1 < n) {
    while (p2 > 0 && b[p2 - 1] >= x - a[p1]) --p2;
    if (p2 < n && a[p1] + b[p2] >= x && a[p1] + b[p2] < mv) mv = a[p1] + b[p2];
    ++p1;
  }
  p1 = 0, p2 = n;
  int ans = 0, have = 0;
  while (p1 < n) {
    while (p2 > 0 && b[p2 - 1] >= mv - a[p1]) {
      --p2;
      ++have;
    }
    if (p2 < n && a[p1] + b[p2] >= mv || have > 0) {
      ++ans;
      --have;
    }
    ++p1;
  }
  cout << 1 << " " << ans;
  return 0;
}
