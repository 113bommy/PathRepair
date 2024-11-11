#include <bits/stdc++.h>
using namespace std;
const double g = 10.0, eps = 1e-9;
const int N = 300000 + 10, maxn = 3000 + 10, inf = 0x3f3f3f3f,
          INF = 0x3f3f3f3f3f3f3f3f;
int d[N], e[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
    for (int j = 2 * i; j <= n; j += i) d[j]++;
  for (int i = 1; i <= n; i++) e[i] = e[i - 1] + d[i];
  if (e[n] < k)
    puts("No");
  else {
    vector<int> ans;
    int te = e[n] - k;
    for (int i = n; i >= 1; i--) {
      if (te >= d[i] + n / i - 1 && d[i] == 1) {
        te -= d[i] + n / i - 1;
        for (int j = 2 * i; j <= n; j += i) d[j]--;
      } else
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    puts("Yes");
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
