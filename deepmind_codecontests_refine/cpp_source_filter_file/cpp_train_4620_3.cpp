#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
const int N = 100007;
int n, m, w[4][4];
struct node {
  int first, last;
  long long cnt[4][4];
  void clear() {
    for (int i = 1; i <= 3; ++i) {
      for (int j = 1; j <= 3; ++j) {
        cnt[i][j] = 0LL;
      }
    }
  }
} T[4 * N];
void combine(const node &left, const node &right, node &vertex) {
  vertex.first = left.first;
  vertex.last = right.last;
  vertex.clear();
  for (int i1 = 1; i1 <= 3; ++i1) {
    for (int j1 = 1; j1 <= 3; ++j1) {
      for (int i2 = 1; i2 <= 3; ++i2) {
        for (int j2 = 1; j2 <= 3; ++j2) {
          vertex.cnt[i1][j2] +=
              w[j1][i2] * left.cnt[i1][j1] * right.cnt[i2][j2];
          vertex.cnt[i1][j2] %= 777777777LL;
        }
      }
    }
  }
}
void build(int v, int tl, int tr) {
  if (tl == tr) {
    T[v].first = 0;
    T[v].last = 0;
    T[v].clear();
    T[v].cnt[1][1] = 1LL;
    T[v].cnt[2][2] = 1LL;
    T[v].cnt[3][3] = 1LL;
    return;
  }
  int tm = (tl + tr) / 2;
  build(2 * v, tl, tm);
  build(2 * v + 1, tm + 1, tr);
  combine(T[2 * v], T[2 * v + 1], T[v]);
}
void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    T[v].first = val;
    T[v].last = val;
    T[v].clear();
    if (val == 0) {
      T[v].cnt[1][1] = 1LL;
      T[v].cnt[2][2] = 1LL;
      T[v].cnt[3][3] = 1LL;
    } else {
      T[v].cnt[val][val] = 1LL;
    }
    return;
  }
  int tm = (tl + tr) / 2;
  if (pos <= tm) {
    update(2 * v, tl, tm, pos, val);
  } else {
    update(2 * v + 1, tm + 1, tr, pos, val);
  }
  combine(T[2 * v], T[2 * v + 1], T[v]);
}
int query() {
  int res = 0;
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      res += T[1].cnt[i][j];
    }
  }
  return res % 777777777LL;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      cin >> w[i][j];
    }
  }
  build(1, 1, n);
  while (m--) {
    int pos, val;
    scanf("%d%d", &pos, &val);
    update(1, 1, n, pos, val);
    printf("%d\n", query());
  }
  return 0;
}
