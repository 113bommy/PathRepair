#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int MOD = 1e9 + 7;
const double pi = acos(-1);
int tree[4 * MAXN][27], lazy[4 * MAXN][27], ct[27];
char str[MAXN], ans[MAXN];
void build(int node, int left, int right) {
  if (left == right) {
    tree[node][(str[left] - 'a')] = 1;
    for (int i = 0; i < 26; i++) lazy[node][i] = -1;
    return;
  }
  int mid = (left + right) / 2;
  build(2 * node, left, mid);
  build(2 * node + 1, mid + 1, right);
  for (int i = 0; i < 26; i++) {
    tree[node][i] = tree[2 * node][i] + tree[2 * node + 1][i];
    lazy[node][i] = -1;
  }
}
int query(int node, int start, int end, int left, int right, int ch) {
  if (lazy[node][ch] != -1) {
    tree[node][ch] = (end - start + 1) * lazy[node][ch];
    if (start != end) {
      lazy[2 * node][ch] = lazy[node][ch];
      lazy[2 * node + 1][ch] = lazy[node][ch];
    }
    lazy[node][ch] = -1;
  }
  if (end < left || start > right) return 0;
  if (start >= left && end <= right) {
    return tree[node][ch];
  }
  int mid = (start + end) / 2;
  return query(2 * node, start, mid, left, right, ch) +
         query(2 * node + 1, mid + 1, end, left, right, ch);
}
void update(int node, int start, int end, int left, int right, int ch,
            int val) {
  if (lazy[node][ch] != -1) {
    tree[node][ch] = (end - start + 1) * lazy[node][ch];
    if (start != end) {
      lazy[2 * node][ch] = lazy[node][ch];
      lazy[2 * node + 1][ch] = lazy[node][ch];
    }
    lazy[node][ch] = -1;
  }
  if (end < left || start > right) return;
  if (start >= left && end <= right) {
    lazy[node][ch] = val;
    tree[node][ch] = (end - start + 1) * lazy[node][ch];
    if (start != end) {
      lazy[2 * node][ch] = lazy[node][ch];
      lazy[2 * node + 1][ch] = lazy[node][ch];
    }
    lazy[node][ch] = -1;
    return;
  }
  int mid = (start + end) / 2;
  update(2 * node, start, mid, left, right, ch, val);
  update(2 * node + 1, mid + 1, end, left, right, ch, val);
  tree[node][ch] = tree[2 * node][ch] + tree[2 * node + 1][ch];
}
void get(int node, int left, int right, int ch) {
  if (lazy[node][ch] != -1) {
    tree[node][ch] = (left - right + 1) * lazy[node][ch];
    if (left != right) {
      lazy[2 * node][ch] = lazy[node][ch];
      lazy[2 * node + 1][ch] = lazy[node][ch];
    }
    lazy[node][ch] = -1;
  }
  if (!tree[node][ch]) return;
  if (left == right) {
    ans[left] = (ch + 'a');
    return;
  }
  int mid = (left + right) / 2;
  get(2 * node, left, mid, ch);
  get(2 * node + 1, mid + 1, right, ch);
}
int main() {
  int n, m;
  cin >> n >> m;
  scanf("%s", str);
  build(1, 0, n - 1);
  while (m--) {
    int l, r, k;
    cin >> l >> r >> k;
    l--;
    r--;
    for (int i = 0; i < 26; i++) {
      ct[i] = query(1, 0, n - 1, l, r, i);
    }
    int pos = l;
    if (k == 1) {
      for (int i = 0; i < 26; i++) {
        if (!ct[i]) continue;
        update(1, 0, n - 1, l, r, i, 0);
        update(1, 0, n - 1, pos, pos + ct[i] - 1, i, 1);
        pos += ct[i];
      }
    } else {
      for (int i = 25; i >= 0; i--) {
        if (!ct[i]) continue;
        update(1, 0, n - 1, l, r, i, 0);
        update(1, 0, n - 1, pos, pos + ct[i] - 1, i, 1);
        pos += ct[i];
      }
    }
  }
  for (int i = 0; i < 26; i++) {
    get(1, 0, n - 1, i);
  }
  printf("%s", ans);
  return 0;
}
