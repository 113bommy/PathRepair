#include <bits/stdc++.h>
using namespace std;
int n, a[200005], b[200005], c[200005], tree[4 * 200005], surplus, val;
void input() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
}
void resetTree(int curr, int left, int right) {
  if (left == right) {
    tree[curr] = 1;
    return;
  }
  int mid = (left + right) >> 1;
  resetTree(2 * curr, left, mid);
  resetTree(2 * curr + 1, mid + 1, right);
  tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}
int ordElem(int curr, int left, int right, int L, int R) {
  if (left > R || right < L) return 0;
  if (L <= left && right <= R) return tree[curr];
  int mid = (left + right) >> 1;
  return ordElem(2 * curr, left, mid, L, R) +
         ordElem(2 * curr + 1, mid + 1, right, L, R);
}
void deleteElem(int curr, int left, int right, int idx) {
  if (left > idx || right < idx) return;
  if (left == right) {
    tree[curr] = 0;
    return;
  }
  int mid = (left + right) >> 1;
  deleteElem(2 * curr, left, mid, idx);
  deleteElem(2 * curr + 1, mid + 1, right, idx);
  tree[curr] = tree[2 * curr] + tree[2 * curr + 1];
}
void getOrd(int x[]) {
  resetTree(1, 0, n - 1);
  for (int i = 0; i < n; i++) {
    c[i] += ordElem(1, 0, n - 1, 0, x[i] - 1);
    deleteElem(1, 0, n - 1, x[i]);
  }
}
void rounding() {
  for (int i = n - 1; i >= 0; i--) {
    c[i] += surplus;
    if (c[i] >= n - i) {
      surplus = c[i] / (n - i);
      c[i] %= n - i;
    } else
      surplus = 0;
  }
}
int findElem(int curr, int left, int right, int pos) {
  if (left == right) return left;
  int mid = (left + right) >> 1;
  int bound = ordElem(2 * curr, left, mid, left, mid);
  if (pos > bound)
    return findElem(2 * curr + 1, mid + 1, right, pos - bound);
  else
    return findElem(2 * curr, left, mid, pos);
}
void buildPermutation() {
  resetTree(1, 0, n - 1);
  for (int i = 0; i < n; i++) {
    val = findElem(1, 0, n - 1, c[i] + 1);
    deleteElem(1, 0, n - 1, val);
    printf("%d%c", val, (i + 1) % n ? ' ' : '\n');
  }
}
int main() {
  input();
  getOrd(a);
  getOrd(b);
  rounding();
  buildPermutation();
  return 0;
}
