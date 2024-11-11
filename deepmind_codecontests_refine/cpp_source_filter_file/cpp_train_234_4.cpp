#include <bits/stdc++.h>
using namespace std;
struct node {
  long long sum, minimum, maximum, lazy;
  node() {
    sum = 0;
    lazy = 0;
  }
  node(long long S, long long Min, long long Max) {
    sum = S;
    minimum = Min;
    maximum = Max;
    lazy = 0;
  }
};
node merge(node &L, node &R) {
  return node(L.sum + R.sum, min(L.minimum, R.minimum),
              max(L.maximum, R.maximum));
}
const int MAX_N = 1e6 + 5, NOT_FOUND = -1, oo = 1e9;
node tree[3 * MAX_N];
void propagate(int n, int left, int right) {
  if (tree[n].lazy == 0) {
    return;
  }
  tree[n].maximum = tree[n].lazy;
  tree[n].minimum = tree[n].lazy;
  tree[n].sum = (right - left + 1) * tree[n].lazy;
  if (left != right) {
    tree[(2 * n)].lazy += tree[n].lazy;
    tree[(2 * n + 1)].lazy += tree[n].lazy;
  }
  tree[n].lazy = 0;
}
void update(int n, int left, int right, int query_left, int query_right,
            long long x) {
  propagate(n, left, right);
  if (right < left || query_right < query_left || query_right < left ||
      right < query_left) {
    return;
  }
  if (query_left <= left && right <= query_right) {
    tree[n].lazy = x;
    propagate(n, left, right);
    return;
  }
  int mid = (left + right) / 2;
  update((2 * n), left, mid, query_left, query_right, x);
  update((2 * n + 1), mid + 1, right, query_left, query_right, x);
  tree[n] = merge(tree[(2 * n)], tree[(2 * n + 1)]);
}
int find_first(int n, int left, int right, int x) {
  propagate(n, left, right);
  if (tree[n].minimum >= x) {
    return oo;
  }
  if (left == right) {
    return right;
  }
  int mid = (left + right) / 2;
  if (tree[(2 * n)].minimum < x) {
    return find_first((2 * n), left, mid, x);
  }
  return find_first((2 * n + 1), mid + 1, right, x);
}
void go_right(int n, int left, int right, int query_left, int query_right,
              int &M, int &C) {
  propagate(n, left, right);
  if (right < query_left || query_right < left) {
    return;
  }
  if (tree[n].minimum > M) {
    return;
  }
  if (query_left <= left && right <= query_right && tree[n].sum <= M) {
    M -= tree[n].sum;
    C += (right - left + 1);
    return;
  }
  int mid = (left + right) / 2;
  go_right((2 * n), left, mid, query_left, query_right, M, C);
  go_right((2 * n + 1), mid + 1, right, query_left, query_right, M, C);
}
int main() {
  int no_of_elements, no_of_queries;
  cin >> no_of_elements >> no_of_queries;
  for (int i = 1; i <= no_of_elements; i++) {
    int x;
    cin >> x;
    update(1, 1, no_of_elements, i, i, x);
  }
  for (int i = 1; i <= no_of_queries; i++) {
    int type, x, y;
    cin >> type >> x >> y;
    const int UPDATE = 1, QUERY = 2;
    switch (type) {
      case UPDATE: {
        int prefix = x, value = y;
        int i = find_first(1, 1, no_of_elements, value);
        update(1, 1, no_of_elements, i, prefix, value);
        break;
      }
      case QUERY: {
        int money = y, start = x;
        int visit_count = 0;
        go_right(1, 1, no_of_elements, start, no_of_elements, money,
                 visit_count);
        cout << visit_count << "\n";
      }
    }
  }
  return 0;
}
