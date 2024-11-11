#include <bits/stdc++.h>
using namespace std;
int n, q;
int perm[300005];
int pos[3000005];
int x, y;
bool bad[300005];
int tree[300005];
int t;
int op;
void update(int x, int val) {
  while (x <= n) {
    tree[x] += val;
    x += x & (-x);
  }
}
int read(int x) {
  int sum = 0;
  while (x > 0) {
    sum += tree[x];
    x -= x & (-x);
  }
  return sum;
}
void correct(int num) {
  if (num <= 0 || num > n) return;
  bool now;
  if (pos[num - 1] < pos[num])
    now = false;
  else
    now = true;
  if (now == bad[num]) return;
  if (now) {
    bad[num] = true;
    update(num, 1);
  } else {
    bad[num] = false;
    update(num, -1);
  }
}
int main() {
  int j;
  scanf("%d", &n);
  pos[0] = n + 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", perm + i);
    pos[perm[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    correct(i);
  }
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1) {
      printf("%d\n", read(y) - read(x) + 1);
    } else {
      j = pos[perm[x]];
      pos[perm[x]] = pos[perm[y]];
      pos[perm[y]] = j;
      j = perm[x];
      perm[x] = perm[y];
      perm[y] = j;
      correct(perm[x]);
      correct(perm[x] - 1);
      correct(perm[x] + 1);
      correct(perm[y]);
      correct(perm[y] - 1);
      correct(perm[y] + 1);
    }
  }
  return 0;
}
