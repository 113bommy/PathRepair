#include <bits/stdc++.h>
using namespace std;
const int MX = 1 << 17;
int A[MX];
struct node {
  int s[30], t[30];
};
node ini;
struct segtree {
  node t[MX * 2];
  node merge(node x, node y) {
    node ans = {0};
    for (int i = 0; i < 30; i++) {
      ans.s[i] = y.s[x.s[i]];
      ans.t[i] = x.t[i] + y.t[x.s[i]];
    }
    return ans;
  }
  void update(int wi) {
    wi += MX;
    for (int i = 0; i < 30; i++) {
      t[wi].s[i] = (i % A[wi - MX] ? i + 1 : i + 2) % 30;
      t[wi].t[i] = (i % A[wi - MX] ? 1 : 2);
    }
    wi /= 2;
    while (wi) {
      t[wi] = merge(t[wi * 2], t[wi * 2 + 1]);
      wi /= 2;
    }
  }
  node read(int ad, int s, int e, int l, int r) {
    if (e < l || r < s)
      return ini;
    else if (l <= s && e <= r)
      return t[ad];
    else {
      int m = (s + e) / 2;
      return merge(read(ad * 2, s, m, l, r), read(ad * 2 + 1, m + 1, e, l, r));
    }
  }
  node read(int s, int e) { return read(1, 0, MX - 1, s, e); }
} tree;
int main() {
  for (int i = 0; i < 30; i++) ini.s[i] = i;
  for (int i = 0; i < MX; i++) A[i] = 2;
  int N, M;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    scanf("%d", A + i);
  }
  for (int i = 0; i < MX; i++) tree.update(i);
  scanf("%d", &M);
  for (int t = 1; t <= M; t++) {
    char O[10];
    scanf("%s", O);
    if (O[0] == 'A') {
      int A, B;
      scanf("%d%d", &A, &B);
      B--;
      printf("%d\n", tree.read(A, B).t[0]);
    } else {
      int X, Y;
      scanf("%d%d", &X, &Y);
      A[X] = Y;
      tree.update(X);
    }
  }
  return 0;
}
