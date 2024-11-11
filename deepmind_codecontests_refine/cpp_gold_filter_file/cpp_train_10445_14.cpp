#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
int n, l, k;
struct Node {
  int a, p;
  bool operator<(const Node &nn) const { return a > nn.a; }
} nodes[maxn];
double d[maxn][maxn * 2];
int main() {
  std::ios::sync_with_stdio(false);
  cin >> n >> l >> k;
  for (int i = 1; i <= n; i++) {
    cin >> nodes[i].p;
  }
  for (int i = 1; i <= n; i++) {
    cin >> nodes[i].a;
  }
  sort(nodes + 1, nodes + n + 1);
  memset(d, 0, sizeof(d));
  k = k + 200;
  for (int i = 0; i <= k; i++) {
    d[0][i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j >= 0; j--) {
      for (int x = 0; x <= 400; x++) {
        d[j][x] = d[j][x] * (100 - nodes[i].p) / 100;
        int tmp = x - nodes[i].a;
        if (tmp < 0) {
          tmp = 0;
        }
        if (tmp > 400) {
          tmp = 400;
        }
        if (j > 0) {
          d[j][x] += d[j - 1][tmp] * nodes[i].p / 100;
        }
      }
    }
  }
  double res = 0;
  for (int j = l; j <= n; j++) {
    res += d[j][200];
  }
  printf("%.12lf\n", res);
  return 0;
}
