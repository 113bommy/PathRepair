#include <bits/stdc++.h>
using namespace std;
struct MonotonicQueue {
  deque<int> Q;
  queue<int> Qu;
  void push(int x) {
    Qu.push(x);
    while (!Q.empty() && Q.back() > x) Q.pop_back();
    Q.push_back(x);
  }
  void pop() {
    int x = Qu.front();
    Qu.pop();
    if (!Q.empty() && Q.front() == x) Q.pop_front();
  }
  int min() { return Q.front(); }
  int size() { return (int)(Qu).size(); }
  void clear() {
    while (!Q.empty()) Q.pop_back();
    while (!Qu.empty()) Qu.pop();
  }
};
const int N = (int)1e5 + 5;
const int K = 228 + 5;
const int INF = (int)1e9;
int pref[K][N][2], suff[2][N][2];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<pair<int, int> > x = {{0, 0}};
  for (int i = 0; i < k; ++i) {
    int l, r;
    scanf("%d %d", &l, &r);
    x.push_back({l, 1});
    x.push_back({r, 0});
  }
  x.push_back({2 * n, 0});
  int last = (int)(x).size() - 1;
  for (int i = 0; i <= last; ++i) {
    for (int w = 0; w <= n; ++w) {
      for (int t = 0; t < 2; ++t) pref[i][w][t] = suff[i & 1][w][t] = INF;
    }
  }
  for (int t = 0; t < 2; ++t) pref[0][0][t] = 0;
  for (int i = 1; i <= last; ++i) {
    int len = x[i].first - x[i - 1].first;
    for (int w = 0; w <= n; ++w)
      pref[i][w][1] = min(pref[i - 1][w][1], pref[i - 1][w][0] + 1);
    for (int w = len; w <= n; ++w)
      pref[i][w][0] = min(pref[i - 1][w - len][0], pref[i - 1][w - len][1] + 1);
  }
  int ans = pref[last][n][0];
  int tl = 0, ntl = 1;
  for (int t = 0; t < 2; ++t) suff[tl][0][t] = 0;
  MonotonicQueue Q[2];
  for (int i = last - 1; i >= 0; --i) {
    int len = x[i + 1].first - x[i].first;
    if (x[i].second) {
      for (int w1 = n, w2 = 0; w1 >= 0; --w1, ++w2) {
        Q[0].push(suff[tl][w2][0]);
        Q[1].push(suff[tl][w2][1]);
        ans = min(ans, pref[i][w1][1] + 1 + Q[0].min());
        ans = min(ans, pref[i][w1][0] + 1 + Q[0].min());
        ans = min(ans, pref[i][w1][1] + 2 + Q[1].min());
        ans = min(ans, pref[i][w1][0] + 1 + Q[1].min());
        if (Q[0].size() == len + 1) Q[0].pop(), Q[1].pop();
      }
      Q[0].clear();
      Q[1].clear();
    }
    for (int w = 0; w <= n; ++w) suff[ntl][w][0] = suff[ntl][w][1] = INF;
    for (int w = 0; w <= n; ++w)
      suff[ntl][w][1] = min(suff[tl][w][1], suff[tl][w][0] + 1);
    for (int w = len; w <= n; ++w)
      suff[ntl][w][0] = min(suff[tl][w - len][0], suff[tl][w - len][1] + 1);
    swap(tl, ntl);
  }
  if (ans == INF) {
    printf("Hungry\n");
  } else {
    printf("Full\n");
    printf("%d\n", ans);
  }
}
