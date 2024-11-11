#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, W;
  cin >> N >> W;
  vector<vector<int>> A(N);
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    int l;
    scanf("%d", &l);
    A[i].resize(l + 2);
    for (int j = 1; j <= l; j++) scanf("%d", &A[i][j]);
    L[i] = l + 2;
  }
  vector<int> order(N);
  for (int i = 0; i < N; i++) order[i] = i;
  sort(order.begin(), order.end(), [&](int i, int j) { return L[i] > L[j]; });
  vector<vector<pair<int, int>>> change(W + 1);
  for (int a = 0; a < N; a++) {
    deque<int> que;
    que.push_back(0);
    for (int w = 1; w <= W; w++) {
      int pos = L[a] - 3 - W + w;
      while (que.size() && que[0] <= pos) que.pop_front();
      if (w < L[a]) {
        while (que.size() && A[a][que.back()] <= A[a][w]) que.pop_front();
        que.push_back(w);
      }
      int mx2 = A[a][que[0]];
      change[w].emplace_back(a, mx2);
      if (w >= L[a]) {
        w = max(w, W + 2 - L[a]);
      }
    }
  }
  vector<int> mx(N, 0);
  int64_t now = 0;
  for (int w = 1; w <= W; w++) {
    for (auto& p : change[w]) {
      int a = p.first, mx2 = p.second;
      now += mx2 - mx[a];
      mx[a] = mx2;
    }
    printf("%lld%c", now, " \n"[w == W]);
  }
  return 0;
}
