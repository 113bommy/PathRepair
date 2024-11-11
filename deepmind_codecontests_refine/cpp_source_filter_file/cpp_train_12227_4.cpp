#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 25;
vector<int> vert_weights;
int n, m;
int main() {
  scanf("%d %d", &n, &m);
  vert_weights.resize(n);
  double vert_sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    vert_weights[i] = x;
    vert_sum += x;
  }
  double ans = -INF;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    a--;
    b--;
    double curr = (vert_weights[a] + vert_weights[b]) / (double)c;
    ans = max(curr, ans);
  }
  printf("%5.10f\n", ans);
}
