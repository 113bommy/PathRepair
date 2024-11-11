#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
const int N = 5e5 + 10;
using namespace std;
int n, m, p;
char str[N];
int dp[N];
stack<int> s;
int cur;
int tree[4 * N];
char op[N];
void build(int l, int r, int x) {
  if (l == r) {
    tree[x] = 0;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, x << 1);
  build(mid + 1, r, x << 1 | 1);
  if (tree[x << 1] == 1 && tree[x << 1 | 1] == 1)
    tree[x] = 1;
  else
    tree[x] = 0;
}
void init() {
  scanf("%s", str + 1);
  memset(dp, 0, sizeof(dp));
  if (!s.empty()) s.pop();
  for (int i = 1; i <= n; i++) {
    if (str[i] == '(') {
      s.push(i);
    } else {
      int r = s.top();
      s.pop();
      dp[i] = r;
      dp[r] = i;
    }
  }
  scanf("%s", op);
  build(1, n, 1);
}
void add(int l, int r, int x, int L, int R) {
  if (L == l && R == r) {
    tree[x] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  if (R <= mid)
    add(l, mid, x << 1, L, R);
  else if (L > mid)
    add(mid + 1, r, x << 1 | 1, L, R);
  else {
    add(l, mid, x << 1, L, mid);
    add(mid + 1, r, x << 1 | 1, mid + 1, R);
  }
  if (tree[x << 1] == 1 && tree[x << 1 | 1] == 1)
    tree[x] = 1;
  else
    tree[x] = 0;
}
int flag;
int queryl(int l, int r, int x, int pos) {
  if (l == r) {
    if (tree[x] == 0) {
      flag = 1;
      return l;
    } else {
      flag = 0;
      return l;
    }
  }
  if (tree[x] == 1) {
    flag = 0;
    return 0;
  }
  int mid = (l + r) >> 1;
  if (pos <= mid) return queryl(l, mid, x << 1, pos);
  int e = queryl(mid + 1, r, x << 1 | 1, pos);
  if (flag)
    return e;
  else
    return queryl(l, mid, x << 1, pos);
}
int queryr(int l, int r, int x, int pos) {
  if (l == r) {
    if (tree[x] == 0) {
      flag = 1;
      return l;
    } else {
      flag = 0;
      return l;
    }
  }
  if (tree[x] == 1) {
    flag = 0;
    return 0;
  }
  int mid = (l + r) >> 1;
  if (pos > mid) return queryr(mid + 1, r, x << 1 | 1, pos);
  int e = queryr(l, mid, x << 1, pos);
  if (flag)
    return e;
  else
    return queryr(mid + 1, r, x << 1 | 1, pos);
}
int read(int l, int r, int x, int pos) {
  if (l == r) return tree[x];
  int mid = (l + r) >> 1;
  if (tree[x] == 1) return 1;
  if (pos <= mid)
    return read(l, mid, x << 1, pos);
  else
    return read(mid + 1, r, x << 1 | 1, pos);
}
int main() {
  int i, j;
  while (~scanf("%d%d%d", &n, &m, &p)) {
    init();
    cur = p;
    for (i = 0; i < m; i++) {
      if (op[i] == 'R') {
        flag = 0;
        cur = queryr(1, n, 1, cur + 1);
      } else if (op[i] == 'L') {
        flag = 0;
        cur = queryl(1, n, 1, cur - 1);
      } else {
        int l = min(dp[cur], cur);
        int r = max(dp[cur], cur);
        add(1, n, 1, l, r);
        if (cur != n) {
          flag = 0;
          int e = queryr(1, n, 1, cur + 1);
          if (flag)
            cur = e;
          else {
            flag = 0;
            cur = queryl(1, n, 1, cur - 1);
          }
        } else {
          flag = 0;
          cur = queryl(1, n, 1, cur - 1);
        }
      }
    }
    for (i = 1; i <= n; i++) {
      if (!read(1, n, 1, i)) printf("%c", str[i]);
    }
    putchar('\n');
  }
  return 0;
}
