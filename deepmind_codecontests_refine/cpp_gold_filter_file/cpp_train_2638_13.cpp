#include <bits/stdc++.h>
using namespace std;
const int N = 2000000;
const int INF = N + 1;
int n, h, m, next[N];
int arr[N], order[N], tree[N];
int *roots[N];
void build(int *tree, int root, int left, int right) {
  if (left == right) {
    tree[root] = left;
  } else {
    int mid = (left + right) / 2;
    build(tree, root * 2, left, mid);
    build(tree, root * 2 + 1, mid + 1, right);
    tree[root] = left;
  }
}
int query(int *tree, int root, int left, int right, int idx) {
  if (left >= idx) {
    return tree[root];
  } else if (right < idx) {
    return INF;
  } else {
    int mid = (left + right) / 2;
    return min(query(tree, root * 2, left, mid, idx),
               query(tree, root * 2 + 1, mid + 1, right, idx));
  }
}
void update(int *tree, int root, int left, int right, int idx, bool add) {
  if (idx < left || idx > right) {
    return;
  }
  if (left == right) {
    if (add) {
      tree[root] = INF;
    } else {
      tree[root] = left;
    }
  } else {
    int mid = (left + right) / 2;
    update(tree, root * 2, left, mid, idx, add);
    update(tree, root * 2 + 1, mid + 1, right, idx, add);
    tree[root] = min(tree[root * 2], tree[root * 2 + 1]);
  }
}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
map<int, int> mp;
map<int, int *> mproot;
char code[2];
int id, pos;
int main() {
  scanf("%d %d %d", &h, &m, &n);
  int g = gcd(h, m);
  int np = (h / g) - 1;
  for (int j = 0; j < g; j++) {
    int idx = 0;
    int cur = j;
    for (int i = j; i < h; i += g) {
      order[cur] = idx++;
      cur = (cur + m) % h;
    }
    roots[j] = tree + ((h / g) * 5 * j);
    build(roots[j], 1, 0, np);
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s %d", code, &id);
    if (code[0] == '+') {
      scanf("%d", &pos);
      int *mroot = roots[pos % g];
      int q = query(mroot, 1, 0, np, order[pos]);
      if (q == INF) {
        sum += np - order[pos] + 1;
        q = query(mroot, 1, 0, np, 0);
        sum += q;
      } else {
        sum += q - order[pos];
      }
      mp[id] = q;
      mproot[id] = mroot;
      update(mroot, 1, 0, np, q, 1);
    } else {
      update(mproot[id], 1, 0, np, mp[id], 0);
    }
  }
  cout << sum << endl;
  return 0;
}
