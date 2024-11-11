#include <bits/stdc++.h>
using namespace std;
void TxtRead() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
}
const int N = 1e5 + 5;
const long long INF = 1e12 + 5;
const long long MOD = 1e9 + 7;
const double PI = 3.141592653589793116;
int n, m, k, x, y, u;
pair<int, int> c[N], r[N];
int main() {
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", &x, &y, &u);
    if (x == 1)
      c[y] = make_pair(i, u);
    else
      r[y] = make_pair(i, u);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (c[i].first > r[j].second)
        printf("%d ", c[i].second);
      else
        printf("%d ", r[j].second);
    }
    printf("\n");
  }
}
