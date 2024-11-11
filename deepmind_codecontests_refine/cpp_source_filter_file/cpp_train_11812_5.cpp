#include <bits/stdc++.h>
using namespace std;
int n;
int a[300005];
int p[300005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) p[i] = p[i - 1] + a[i];
  long long ans = 0;
  queue<pair<int, int> > q;
  q.push({1, n});
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    if (x > y) continue;
    ans += (p[y] - p[x - 1]);
    if (x == y) {
      continue;
    }
    q.push({x, x});
    q.push({x + 1, y});
  }
  cout << ans << '\n';
  return 0;
}
