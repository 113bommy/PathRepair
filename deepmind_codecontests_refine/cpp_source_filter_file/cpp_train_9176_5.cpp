#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;
int test_case;
int N;
int ans[MAXN];
int SEG[MAXN];
vector<pair<int, int> > A;
void update(int node, int l, int r, int x, int val) {
  if (x < l || r < x) return;
  SEG[node]++;
  if (l == r) return;
  int mid = (l + r) / 2;
  update(node * 2, l, mid, x, val);
  update(node * 2 + 1, mid + 1, r, x, val);
}
int query(int node, int l, int r, int x, int y) {
  if (y < l || r < x) return 0;
  if (x <= l && r <= y) return SEG[node];
  int mid = (l + r) / 2;
  return query(node * 2, l, mid, x, y) + query(node * 2 + 1, mid + 1, r, x, y);
}
void init() {
  scanf("%d", &N);
  for (int i = 0; i <= (N + 1); i++) ans[i] = 0;
  for (int i = 0; i <= (N + 1) * 4; i++) SEG[i] = 0;
  A.clear();
  int x;
  for (int i = 1; i <= N; i++) scanf("%d", &x), A.push_back({x, i});
  ans[N + 1] = N + 1;
  update(1, 1, N + 1, N + 1, N + 1);
}
int main(void) {
  scanf("%d", &test_case);
  for (int t = 1; t <= test_case; t++) {
    init();
    sort(A.begin(), A.end(), [&](pair<int, int> X, pair<int, int> Y) {
      if (X.first != Y.first) return X.first > Y.first;
      return X.second < Y.second;
    });
    int ck = 0;
    int pos = N;
    for (pair<int, int> x : A) {
      int val = x.first;
      int ind = x.second;
      if (val == -1) break;
      if (ans[ind]) {
        ck = 1;
        break;
      }
      if (ans[val] == 0) {
        ans[val] = pos;
        update(1, 1, N + 1, val, pos);
        pos--;
      }
      if (query(1, 1, N + 1, ind + 1, val - 1)) {
        ck = 1;
        break;
      } else {
        ans[ind] = pos, update(1, 1, N + 1, ind, pos);
        pos--;
      }
    }
    if (ck)
      printf("-1\n");
    else {
      for (int i = 1; i <= N; i++)
        if (ans[i] == 0) ans[i] = pos--;
      for (int i = 1; i <= N; i++) printf("%d ", ans[i]);
      printf("\n");
    }
  }
  return 0;
}
