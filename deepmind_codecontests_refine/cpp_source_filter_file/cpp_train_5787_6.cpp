#include <bits/stdc++.h>
using namespace std;
int c[100010], w[100010], A[100010], B[100010];
struct Node {
  int x;
  long long y;
  inline bool operator<(const Node& rhs) const { return y < rhs.y; }
};
set<Node> S;
int main() {
  int n;
  long long m;
  scanf("%d%lld", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
    A[i] = c[i] / 100;
    B[i] = c[i] % 100;
    if (B[i] == 0) {
      A[i]++;
      B[i] = 100;
    }
  }
  long long Ans = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &w[i]);
  }
  for (int i = 1; i <= n; ++i) {
    m -= B[i];
    S.insert((Node){i, 1ll * (100 - B[i]) * w[i]});
    if (m < 0) {
      m += 100;
      Node u = (*S.begin());
      Ans += u.y;
      A[u.x]++;
      B[u.x] = 0;
      S.erase(S.begin());
    }
  }
  printf("%lld\n", Ans);
  for (int i = 1; i <= n; ++i) {
    printf("%d %d\n", A[i], B[i]);
  }
}
