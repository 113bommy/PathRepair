#include <bits/stdc++.h>
using namespace std;
int x1[201][201];
int y11[201][201];
int G[201][201];
const int maxn = 2 * 1234;
struct he {
  int x, y;
} Sky[maxn];
int n;
void init() {
  for (int i = 1; i <= n; i++) scanf("%d%d", &Sky[i].x, &Sky[i].y);
}
void play() {
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    memset(x1, 0, sizeof(x1));
    memset(y11, 0, sizeof(y11));
    int l = 0;
    int r = 0;
    for (int j = i + 1; j <= n; j++) {
      int q = Sky[i].y - Sky[j].y;
      int p = Sky[i].x - Sky[j].x;
      if (p == 0) {
        l++;
      } else if (q == 0) {
        r++;
      } else {
        int nn = G[abs(q)][abs(p)];
        q /= nn;
        p /= nn;
        if (q > 0 && p > 0) {
          x1[q][p]++;
        } else if (q < 0 && p < 0) {
          x1[-q][-p]++;
        } else {
          y11[abs(q)][abs(p)]++;
        }
      }
    }
    long long sum = 0;
    int sk = n - i;
    if (l != 0) {
      sum += (sk - l);
    }
    if (r != 0) {
      sum += (sk - r);
    }
    for (int j = 1; j <= 200; j++) {
      for (int k = 1; k <= 200; k++) {
        int p = x1[j][k];
        int q = y11[j][k];
        if (p != 0) {
          sum += (sk - p) * p;
        }
        if (q != 0) {
          sum += (sk - q) * q;
        }
      }
    }
    sum /= 2;
    ans += sum;
  }
  printf("%I64d\n", ans);
}
int GCD(int a, int b) {
  if (a < b) swap(a, b);
  if (a % b != 0) {
    return GCD(b, a % b);
  }
  return b;
}
int main() {
  for (int i = 1; i <= 200; i++) {
    for (int j = 1; j <= 200; j++) {
      G[i][j] = GCD(i, j);
    }
  }
  while (scanf("%d", &n) != EOF) {
    init();
    play();
  }
  return 0;
}
