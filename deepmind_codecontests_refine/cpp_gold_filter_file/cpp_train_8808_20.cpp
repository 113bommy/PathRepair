#include <bits/stdc++.h>
using namespace std;
const int N = 3000;
const int mo = 1e9 + 7;
unsigned long long c[N][N];
int n, m, q;
int lowbit(int x) { return x & -x; }
struct node {
  int x1, y1, x2, y2;
  bool operator<(const node res) const {
    if (x1 != res.x1) return x1 < res.x1;
    if (y1 != res.y1) return y1 < res.y1;
    if (x2 != res.x2) return x2 < res.x2;
    return y2 < res.y2;
  }
};
map<node, long long> dict;
void add(int x, int y, unsigned long long val) {
  for (int i = x; i <= n; i += lowbit(i)) {
    for (int j = y; j <= m; j += lowbit(j)) c[i][j] += val;
  }
}
unsigned long long sum(int x, int y) {
  unsigned long long ret = 0;
  for (int i = x; i > 0; i -= lowbit(i)) {
    for (int j = y; j > 0; j -= lowbit(j)) ret += c[i][j];
  }
  return ret;
}
long long rnd() {
  double rando = rand() / (double)(RAND_MAX);
  rando = rando * (1LL << 60);
  return (long long)rando;
}
long long getrand(int x) { return 1LL * rand() * rand() % mo + x; }
int main() {
  srand(time(0));
  scanf("%d%d%d", &n, &m, &q);
  while (q--) {
    int t, x1, x2, y1, y2;
    scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
    if (t == 1) {
      long long &e = dict[(node){x1, y1, x2, y2}];
      e = getrand(q);
      add(x1, y1, e);
      add(x2 + 1, y1, -e);
      add(x1, y2 + 1, -e);
      add(x2 + 1, y2 + 1, e);
    } else if (t == 2) {
      long long e = dict[(node){x1, y1, x2, y2}];
      add(x1, y1, -e);
      add(x2 + 1, y1, e);
      add(x1, y2 + 1, e);
      add(x2 + 1, y2 + 1, -e);
    } else {
      int ans1 = sum(x1, y1), ans2 = sum(x2, y2);
      printf("%s\n", (ans1 == ans2) ? "Yes" : "No");
    }
  }
  return 0;
}
