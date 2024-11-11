#include <bits/stdc++.h>
using namespace std;
const long long INF = 100000000000000LL;
int h, n, p, pp;
map<int, int> M;
bool isLeaf(int x) { return ((x > p) && (x <= pp)); }
double res;
void solve(int x, int m, double p) {
  if (isLeaf(x)) {
    res += max(m, M[x]) * p;
  } else {
    int l = M[x] - M[x * 2 + 1];
    int r = M[x] - M[x * 2];
    if (l == r)
      res += max(m, l) * p;
    else if (l > r) {
      res += max(l, m) * p * 0.5;
      solve(x * 2, max(m, r), p * 0.5);
    } else {
      res += max(r, m) * p * 0.5;
      solve(x * 2 + 1, max(m, l), p * 0.5);
    }
  }
}
int main() {
  cin >> h >> n;
  p = 0;
  for (int i = 0; i < h; i++) p += (1 << i);
  pp = p + (1 << h);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (s == "add") {
      int u, v;
      scanf("%d%d", &u, &v);
      while (true) {
        M[u] += v;
        if (u == 1) break;
        u = u / 2;
      }
    } else {
      res = 0;
      solve(1, 0, 1.0);
      printf("%0.12f\n", res);
    }
  }
  return 0;
}
