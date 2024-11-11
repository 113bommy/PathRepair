#include <bits/stdc++.h>
using namespace std;
struct node {
  int x, y;
  long long val;
  bool operator<(const node &b) const { return val < b.val; }
};
int n, m, k, r;
long long f(int x, int y) {
  return 1LL * (min(y, m - r + 1) - max(1, y - r + 1) + 1) *
         (min(x, n - r + 1) - max(1, x - r + 1) + 1);
}
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
priority_queue<node> pq;
map<pair<int, int>, bool> viz;
long long sum = 0;
bool isInBounds(int x, int y) { return 1 <= x && x <= n && 1 <= y && y <= m; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> r >> k;
  viz[{(n + 1) / 2, (m + 1) / 2}] = true;
  pq.push({(n + 1) / 2, (m + 1) / 2, f((n + 1) / 2, (m + 1) / 2)});
  while (pq.empty() == false && k) {
    k--;
    node tp = pq.top();
    pq.pop();
    sum += tp.val;
    for (int i = 0; i < 4; i++) {
      int x = tp.x + d[i][0];
      int y = tp.y + d[i][1];
      if (isInBounds(x, y) && viz[{x, y}] == false) {
        viz[{x, y}] = true;
        pq.push({x, y, f(x, y)});
      }
    }
  }
  cout << fixed << setprecision(9)
       << (double)sum / (1LL * (n - r + 1) * (m - r + 1));
  return 0;
}
