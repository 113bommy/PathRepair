#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100005;
int C[MAX_N], n;
int lowbit(int x) { return x & (-x); }
int sum(int x) {
  int ans = 0;
  while (x > 0) {
    ans += C[x];
    x -= lowbit(x);
  }
  return ans;
}
void add(int x, int d) {
  while (x <= n) {
    C[x] += d;
    x += lowbit(x);
  }
}
int main() {
  int q, L, R, turn = 0;
  scanf("%d%d", &n, &q);
  R = n, L = 0;
  for (int i = 1; i <= n; i++) add(i, 1);
  for (int cc = 0; cc < q; ++cc) {
    int op, a, b;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &a);
      int Len = R - L;
      if ((a > Len / 2 && turn == 0)) {
        int LEN = Len - a;
        a = R - LEN;
        for (int loc = 1; loc <= LEN; ++loc) {
          int E = sum(a + loc) - sum(a + loc - 1);
          add(a - loc + 1, E);
        }
        turn = 1;
        R = a;
        continue;
      }
      if ((a <= Len / 2 && turn == 1)) {
        int LEN = a;
        a = R - LEN;
        for (int loc = 1; loc <= LEN; ++loc) {
          int E = sum(a + loc) - sum(a + loc - 1);
          add(a - loc + 1, E);
        }
        R = a;
        continue;
      }
      if ((a > (Len / 2) && turn == 1)) {
        int LEN = Len - a;
        a = L + LEN;
        for (int loc = 0; loc < LEN; ++loc) {
          int E = sum(a + loc) - sum(a + loc - 1);
          add(a + loc + 1, E);
        }
        L = a;
        turn = 0;
        continue;
      }
      if (a <= Len / 2 && turn == 0) {
        int LEN = a;
        a = L + a;
        for (int loc = 0; loc < LEN; ++loc) {
          int E = sum(a - loc) - sum(a - loc - 1);
          add(a + loc + 1, E);
        }
        L = a;
        continue;
      }
    } else {
      scanf("%d%d", &a, &b);
      int ans;
      if (turn == 0) {
        ans = sum(L + b) - sum(L + a);
      } else {
        ans = sum(R - a) - sum(R - b);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
