#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
const int INF = 1e9 + 5;
int n, m, s;
int A[MAXN], B[MAXN], C0[MAXN], C[MAXN];
int bugsOrder[MAXN], studentsOrder[MAXN];
int buf[MAXN];
int ans[MAXN];
bool cmpA(int a, int b) { return A[a] > A[b]; }
bool cmpB(int a, int b) { return B[a] > B[b]; }
int startSegTree[4 * MAXN + 1], currSegTree[4 * MAXN + 1];
void build_tree(int *tree, int i, int l, int r) {
  if (l == r) {
    tree[i] = l;
    return;
  }
  int mid = ((l + r) >> 1);
  int il = (i << 1), ir = il + 1;
  build_tree(tree, il, l, mid);
  build_tree(tree, ir, mid + 1, r);
  int al = tree[il], ar = tree[ir];
  tree[i] = C0[al] < C0[ar] ? al : ar;
}
int get_min(int *tree, int i, int l, int r, int a, int b) {
  if (a == l && b == r) return tree[i];
  int mid = ((l + r) >> 1);
  int il = (i << 1), ir = il + 1;
  if (b <= mid) return get_min(tree, il, l, mid, a, b);
  if (mid < a) return get_min(tree, ir, mid + 1, r, a, b);
  int al = get_min(tree, il, l, mid, a, mid);
  int ar = get_min(tree, ir, mid + 1, r, mid + 1, b);
  return C[al] < C[ar] ? al : ar;
}
void set_elem(int *tree, int i, int l, int r, int idx) {
  if (l == r) return;
  int mid = ((l + r) >> 1);
  int il = (i << 1), ir = il + 1;
  if (idx <= mid)
    set_elem(tree, il, l, mid, idx);
  else
    set_elem(tree, ir, mid + 1, r, idx);
  int al = tree[il], ar = tree[ir];
  tree[i] = C[al] < C[ar] ? al : ar;
}
int find_rightest(int val) {
  if (B[0] < val) return -1;
  int beg = 0, end = n - 1, mid;
  while (beg + 1 < end) {
    mid = ((beg + end) >> 1);
    if (B[mid] >= val)
      beg = mid;
    else
      end = mid - 1;
  }
  return B[end] >= val ? end : beg;
}
bool calc_cost(int days, int *ans) {
  int cost = 0;
  int bug = 0;
  memcpy(C, C0, sizeof(C0));
  memcpy(currSegTree, startSegTree, sizeof(startSegTree));
  while (bug < m) {
    int rightest = find_rightest(A[bug]);
    if (rightest == -1) return false;
    int student = get_min(currSegTree, 1, 0, n - 1, 0, rightest);
    cost += C[student];
    if (cost > s) return false;
    C[student] = INF;
    set_elem(currSegTree, 1, 0, n - 1, student);
    for (int i = 0; i < days && bug < m; ++i) ans[bug++] = student;
  }
  return true;
}
int main() {
  int i;
  scanf("%d%d%d", &n, &m, &s);
  for (i = 0; i < m; ++i) scanf("%d", A + i);
  for (i = 0; i < n; ++i) scanf("%d", B + i);
  for (i = 0; i < n; ++i) scanf("%d", C0 + i);
  for (i = 0; i < m; ++i) bugsOrder[i] = i;
  sort(bugsOrder, bugsOrder + m, cmpA);
  for (i = 0; i < m; ++i) buf[i] = A[bugsOrder[i]];
  memcpy(A, buf, sizeof(buf));
  for (i = 0; i < n; ++i) studentsOrder[i] = i;
  sort(studentsOrder, studentsOrder + n, cmpB);
  for (i = 0; i < n; ++i) buf[i] = B[studentsOrder[i]];
  memcpy(B, buf, sizeof(buf));
  for (i = 0; i < n; ++i) buf[i] = C0[studentsOrder[i]];
  memcpy(C0, buf, sizeof(buf));
  build_tree(startSegTree, 1, 0, n - 1);
  int beg = 1, end = m, mid;
  if (!calc_cost(m, buf)) {
    puts("NO");
    return 0;
  }
  while (beg + 1 < end) {
    mid = ((beg + end) >> 1);
    if (calc_cost(mid, buf))
      end = mid;
    else
      beg = mid + 1;
  }
  if (!calc_cost(beg, buf)) calc_cost(end, buf);
  for (i = 0; i < m; ++i) ans[bugsOrder[i]] = studentsOrder[buf[i]];
  puts("YES");
  for (i = 0; i < m; ++i) printf("%d ", ans[i] + 1);
  putchar('\n');
  return 0;
}
