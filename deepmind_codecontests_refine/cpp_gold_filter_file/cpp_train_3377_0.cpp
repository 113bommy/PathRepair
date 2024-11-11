#include <bits/stdc++.h>
using namespace std;
bool can[100006];
bool invi[100006];
vector<pair<int, int> > queries(100006);
vector<vector<int> > in(100006), out(100006);
int TREE[4 * 100006];
void update(int node, int left, int right, int idx, int val) {
  if (idx < left || right < idx) return;
  if (left == right) {
    TREE[node] = val;
    return;
  }
  int mid = (left + right) / 2;
  update(2 * node, left, mid, idx, val);
  update(2 * node + 1, mid + 1, right, idx, val);
  TREE[node] = ((TREE[2 * node]) > (TREE[2 * node + 1]) ? (TREE[2 * node])
                                                        : (TREE[2 * node + 1]));
}
bool query(int node, int left, int right, int start, int end) {
  if (start > end) return false;
  if (end < left || right < start) return false;
  if (start <= left && right <= end) return TREE[node] != 0;
  int mid = (left + right) / 2;
  bool l = query(2 * node, left, mid, start, end);
  bool r = query(2 * node + 1, mid + 1, right, start, end);
  return l | r;
}
void print(int N) {
  int ans = 0;
  int i;
  for (i = 1; i <= N; ++i) ans += can[i];
  printf("%d\n", ans);
  if (!ans) return;
  for (i = 1; i <= N; ++i) {
    if (!can[i]) continue;
    printf("%d", i);
    --ans;
    if (ans) putchar(' ');
  }
  puts("");
}
void print2(int n) {
  printf("for %d\n", n);
  int i;
  for (i = 0; i < in[n].size(); ++i) printf("%d ", in[n][i]);
  puts("");
  for (i = 0; i < out[n].size(); ++i) printf("%d ", out[n][i]);
  puts("");
}
int main() {
  int N, Q, i, x, st, cur, q, c, start, end;
  bool d;
  char op[6];
  while (scanf("%d %d", &N, &Q) != EOF) {
    for (i = 1; i <= N; ++i) {
      invi[i] = true;
      in[i].clear(), out[i].clear();
      can[i] = true;
    }
    queries.clear();
    st = 0;
    queries.push_back(make_pair(-1, -1));
    for (q = 1; q <= Q; ++q) {
      scanf("%s %d", op, &x);
      if (op[0] == '+')
        queries.push_back(make_pair(0, x));
      else {
        queries.push_back(make_pair(1, x));
        if (invi[x]) {
          ++st;
          in[x].push_back(0);
        }
      }
      invi[x] = false;
    }
    memset(TREE, 0, sizeof(TREE));
    cur = st;
    for (q = 1; q <= Q; ++q) {
      d = queries[q].first, x = queries[q].second;
      if (d == 0) {
        ++cur;
        in[x].push_back(q);
        update(1, 1, Q + 1, q, cur);
      } else {
        --cur;
        out[x].push_back(q);
        update(1, 1, Q + 1, q, cur);
      }
    }
    update(1, 1, Q + 1, Q + 1, cur);
    for (i = 1; i <= N; ++i) {
      sort(in[i].begin(), in[i].end());
      sort(out[i].begin(), out[i].end());
      if (in[i].size() && in[i][0] > 0 && st) can[i] = false;
      if (in[i].size() && query(1, 1, Q + 1, 1, in[i][0] - 1)) can[i] = false;
      for (c = 1; c < in[i].size() && c - 1 < out[i].size(); ++c) {
        start = out[i][c - 1];
        end = in[i][c] - 1;
        if (query(1, 1, Q + 1, start, end)) can[i] = false;
      }
      if (in[i].size() == 0 || out[i].size() == 0) continue;
      if (!can[i] || in[i][in[i].size() - 1] > out[i][out[i].size() - 1])
        continue;
      start = out[i][out[i].size() - 1];
      end = Q + 1;
      if (query(1, 1, Q + 1, start, end)) can[i] = false;
    }
    print(N);
  }
  return 0;
}
