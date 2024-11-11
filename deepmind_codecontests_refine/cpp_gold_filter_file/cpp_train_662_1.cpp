#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = 1e2 + 7;
const long long INF = 1e17 + 7;
int n, m, p, d[N];
long long sum[N];
struct Node {
  int t, h;
  void in() { scanf("%d%d", &h, &t); }
  bool operator<(const Node &p) const { return t - h < p.t - p.h; }
} a[N];
struct SlopeOp {
  deque<pair<int, long long> > que;
  void push(int x, long long y) {
    while (que.size() > 1) {
      pair<int, long long> fi = que.at(que.size() - 2);
      pair<int, long long> se = que.back();
      if ((fi.second - se.second) * (se.first - x) <
          (se.second - y) * (fi.first - se.first))
        break;
      que.pop_back();
    }
    que.push_back(make_pair(x, y));
  }
  long long get(long long k) {
    while (que.size() > 1) {
      pair<int, long long> fi = que.front();
      pair<int, long long> se = que.at(1);
      if (fi.second - se.second < k * (fi.first - se.first)) break;
      que.pop_front();
    }
    return que.front().second - k * que.front().first;
  }
} so[M];
int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = (2); i < (n + 1); ++i) {
    scanf("%d", &d[i]);
    d[i] += d[i - 1];
  }
  for (int i = (1); i < (m + 1); ++i) {
    a[i].in();
    a[i].h = d[a[i].h];
  }
  sort(a + 1, a + m + 1);
  for (int i = (1); i < (m + 1); ++i) sum[i] = sum[i - 1] + a[i].t - a[i].h;
  so[0].push(0, 0);
  long long ans = INF;
  for (int i = (1); i < (m + 1); ++i) {
    long long T = a[i].t - a[i].h;
    for (int j = min(i, p); j > 0; --j) {
      long long dp = so[j - 1].get(T) + i * T - sum[i];
      so[j].push(i, dp + sum[i]);
      if (i == m) ans = min(ans, dp);
    }
  }
  printf("%lld", ans);
  return 0;
}
