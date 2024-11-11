#include <bits/stdc++.h>
using namespace std;
const int N = 400005;
multiset<int> S;
int x, y, n, m, k;
map<pair<int, int>, int> flag;
struct Tree {
  int l, r, num, flag;
} T[N * 4];
void build(int x, int l, int r) {
  T[x].l = l;
  T[x].r = r;
  if (l == r) {
    T[x].num = l - 1;
    return;
  }
  int mid = (l + r) / 2;
  build(x * 2, l, mid);
  build(x * 2 + 1, mid + 1, r);
  T[x].num = max(T[x * 2].num, T[x * 2 + 1].num);
}
void down(int x) {
  T[x * 2].num += T[x].flag;
  T[x * 2 + 1].num += T[x].flag;
  T[x * 2].flag += T[x].flag;
  T[x * 2 + 1].flag += T[x].flag;
  T[x].flag = 0;
}
void insert(int x, int l, int r, int z) {
  if (T[x].l > r || l > T[x].r) return;
  if (T[x].l >= l && T[x].r <= r) {
    T[x].num += z;
    T[x].flag += z;
    return;
  }
  down(x);
  insert(x * 2, l, r, z);
  insert(x * 2 + 1, l, r, z);
  T[x].num = max(T[x * 2].num, T[x * 2 + 1].num);
}
int find(int x, int l, int r) {
  if (T[x].l > r || l > T[x].r) return 0;
  if (T[x].l >= l && T[x].r <= r) return T[x].num;
  down(x);
  return max(find(x * 2, l, r), find(x * 2 + 1, l, r));
}
int main() {
  scanf("%d%d%d", &n, &k, &m);
  build(1, 1, n + n);
  S.insert(n + 1);
  while (m--) {
    scanf("%d%d", &x, &y);
    if (flag[make_pair(x, y)]) {
      S.erase(S.find(y + abs(x - k)));
      flag[make_pair(x, y)] = 0;
      insert(1, 1, y + abs(x - k), -1);
    } else {
      S.insert(y + abs(x - k));
      flag[make_pair(x, y)] = 1;
      insert(1, 1, y + abs(x - k), 1);
    }
    printf("%d\n", find(1, 1, *S.rbegin()) - n);
  }
}
