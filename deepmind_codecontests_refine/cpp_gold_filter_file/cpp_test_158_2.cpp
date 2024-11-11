#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 10;
const int MOD = 998244353;
int x[11], p[MAX], q[MAX], ret[MAX];
char s[11][MAX];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", x + i);
    for (int i = 0; i < n; i++) scanf("%s", s[i] + 1);
    long long ans = 0;
    for (int i = 0; i < (1 << n); i++) {
      for (int j = 1; j <= m; j++) p[j] = 0;
      for (int j = 1; j <= m; j++) q[j] = j;
      long long sum = 0;
      for (int j = 0; j < n; j++) {
        int tag = ((1 << j) & i) ? 1 : -1;
        sum -= tag * x[j];
        for (int k = 1; k <= m; k++) {
          if (s[j][k] == '0') continue;
          p[k] += tag;
        }
      }
      sort(q + 1, q + m + 1, [](int x, int y) { return p[x] < p[y]; });
      for (int j = 1; j <= m; j++) sum += p[q[j]] * j;
      if (sum >= ans) {
        ans = sum;
        for (int j = 1; j <= m; j++) ret[q[j]] = j;
      }
    }
    for (int i = 1; i <= m; i++) printf("%d ", ret[i]);
    cout << endl;
  }
  return 0;
}
