#include <bits/stdc++.h>
using namespace std;
int N, min_tree[500900], ar[300090], max_tree[1000000], pos[300090];
int update_max_tree(int node, int beg, int end, int L, int V) {
  if (beg > L || end < L) {
    return max_tree[node];
  }
  if (beg == end && beg == L) {
    max_tree[node] = V;
    return max_tree[node];
  }
  int P = update_max_tree(node * 2, beg, (beg + end) / 2, L, V);
  int Q = update_max_tree(node * 2 + 1, (beg + end) / 2 + 1, end, L, V);
  max_tree[node] = P + Q;
  return max_tree[node];
}
int query_tree(int node, int beg, int end, int L, int R) {
  if (beg > R || end < L) {
    return 0;
  }
  if (beg >= L && end <= R) {
    return max_tree[node];
  }
  int P = query_tree(node * 2, beg, (beg + end) / 2, L, R);
  int Q = query_tree(node * 2 + 1, (beg + end) / 2 + 1, end, L, R);
  return P + Q;
}
int main() {
  while (cin >> N) {
    memset(max_tree, 0, sizeof(max_tree));
    for (int i = 0, _n = N; i < _n; i++) {
      scanf("%d", &ar[i]);
      pos[ar[i]] = i;
    }
    for (int i = 2, _n = N + 1; i < _n; i++) {
      if (pos[i] < pos[i - 1]) {
        update_max_tree(1, 0, N, i, 1);
      }
    }
    int Q;
    scanf("%d", &Q);
    while (Q--) {
      int T, x, y;
      cin >> T >> x >> y;
      if (T == 1) {
        int maxi = query_tree(1, 0, N, x + 1, y);
        cout << maxi + 1 << endl;
      } else {
        int u = x - 1, v = y - 1;
        x = ar[x - 1];
        y = ar[y - 1];
        swap(ar[u], ar[v]);
        int newpx = pos[y];
        int newpy = pos[x];
        pos[x] = newpx;
        pos[y] = newpy;
        if (pos[x - 1] > pos[x]) {
          update_max_tree(1, 0, N, x, 1);
        } else {
          update_max_tree(1, 0, N, x, 0);
        }
        if (x + 1 <= N && pos[x + 1] < pos[x]) {
          update_max_tree(1, 0, N, x + 1, 1);
        } else {
          update_max_tree(1, 0, N, x + 1, 0);
        }
        if (pos[y - 1] > pos[y]) {
          update_max_tree(1, 0, N, y, 1);
        } else {
          update_max_tree(1, 0, N, y, 0);
        }
        if (y + 1 <= N && pos[y + 1] < pos[y]) {
          update_max_tree(1, 0, N, y + 1, 1);
        } else {
          update_max_tree(1, 0, N, y + 1, 0);
        }
      }
    }
  }
  return 0;
}
