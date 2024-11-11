#include <bits/stdc++.h>
using namespace std;
struct Hash {
  int num[2];
  void set(int x, int y) { num[0] = x, num[1] = y; }
  Hash operator*(const Hash &A) const {
    Hash res;
    res.num[0] = (1LL * num[0] * A.num[0]) % 1000000007;
    res.num[1] = (1LL * num[1] * A.num[1]) % 1000000009;
    return res;
  }
  Hash operator+(const Hash &A) const {
    Hash res;
    res.num[0] = (num[0] + A.num[0]) % 1000000007;
    res.num[1] = (num[1] + A.num[1]) % 1000000009;
    return res;
  }
  bool operator==(const Hash &A) const {
    return A.num[0] == num[0] && A.num[1] == num[1];
  }
} based[100005], num[10][100005];
struct node {
  int L, R, x;
  int len() { return (R - L + 1); }
  Hash num;
} tree[100005 << 2];
char str[100005];
void down(int p) {
  int &t = tree[p].x;
  if (t == -1) return;
  tree[2 * p].x = t;
  tree[2 * p].num = num[t][tree[2 * p].len()];
  tree[2 * p + 1].x = t;
  tree[2 * p + 1].num = num[t][tree[2 * p + 1].len()];
  t = -1;
}
void up(int p) {
  tree[p].num =
      tree[2 * p].num * based[tree[2 * p + 1].len()] + tree[2 * p + 1].num;
}
void build(int L, int R, int p) {
  tree[p].L = L, tree[p].R = R;
  tree[p].x = -1;
  if (L == R) {
    tree[p].num.set(str[L] - '0', str[L] - '0');
    return;
  }
  int mid = (L + R) >> 1;
  build(L, mid, 2 * p);
  build(mid + 1, R, 2 * p + 1);
  up(p);
}
void update(int L, int R, int c, int p) {
  if (tree[p].L == L && R == tree[p].R) {
    tree[p].x = c;
    tree[p].num = num[c][R - L + 1];
    return;
  }
  down(p);
  int mid = (tree[p].L + tree[p].R) >> 1;
  if (R <= mid)
    update(L, R, c, 2 * p);
  else if (L > mid)
    update(L, R, c, 2 * p + 1);
  else {
    update(L, mid, c, 2 * p);
    update(mid + 1, R, c, 2 * p + 1);
  }
  up(p);
}
Hash query(int L, int R, int p) {
  if (tree[p].L == L && tree[p].R == R) {
    return tree[p].num;
  }
  down(p);
  int mid = (tree[p].L + tree[p].R) >> 1;
  if (R <= mid)
    return query(L, R, 2 * p);
  else if (L > mid)
    return query(L, R, 2 * p + 1);
  else {
    return query(L, mid, 2 * p) * based[R - mid] + query(mid + 1, R, 2 * p + 1);
  }
}
int main() {
  int n, m, k, i, j, a, b, c;
  scanf("%d %d %d", &n, &m, &k);
  m += k;
  scanf("%s", str + 1);
  Hash tmp;
  tmp.set(233, 233);
  based[0].set(0, 0);
  for (i = 1; i <= n; i++) based[i] = based[i - 1] * tmp;
  Hash one;
  for (i = 0; i < 10; i++) {
    num[i][0].set(0, 0);
    one.set(i, i);
    for (j = 1; j <= n; j++) {
      num[i][j] = num[i][j - 1] * tmp + one;
    }
  }
  build(1, n, 1);
  while (m-- && scanf("%d %d %d %d", &k, &a, &b, &c)) {
    if (k == 1) {
      update(a, b, c, 1);
    } else {
      if (b - a + 1 == c)
        puts("YES");
      else {
        puts(query(a, b - c, 1) == query(a + c, b, 1) ? "YES" : "NO");
      }
    }
  }
  return 0;
}
