#include <bits/stdc++.h>
using namespace std;
int a[20];
int srt(int l, int r) {
  vector<int> e;
  for (int i = l; i < r; i++) e.push_back(a[i]);
  sort(e.begin(), e.end());
  for (int i = 0; i < r - l; i++)
    if (e[i] != a[i + l]) return 0;
  return (r - l);
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  queue<pair<int, int> > q;
  q.push({0, n});
  int ans = 0;
  while (!q.empty()) {
    pair<int, int> e = q.front();
    q.pop();
    int l = e.first;
    int r = e.second;
    ans = max(ans, srt(l, r));
    int m = (l + r) / 2;
    if (m == l || m == r) continue;
    q.push({l, m - 1});
    q.push({m, r});
  }
  cout << ans;
}
