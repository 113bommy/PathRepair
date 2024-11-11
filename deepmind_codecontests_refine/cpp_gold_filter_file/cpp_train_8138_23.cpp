#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 5;
const int MOD = 1e9 + 7;
int a[maxn];
int ans[maxn];
vector<int> vec[maxn];
long long sum[maxn];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int last = 0, x;
  scanf("%d", &last);
  long long ans = 0;
  for (int i = 0; i < m - 1; i++) {
    scanf("%d", &x);
    int Min = min(last, x), Max = max(last, x);
    ans += Max - Min;
    last = x;
    if (Min == Max) continue;
    sum[Min] += Min - 1;
    sum[Min + 1] -= Min - 1;
    sum[Max] += (2 * Min - Max);
    sum[Max + 1] -= (2 * Min - Max);
    if (Max - Min > 1) {
      sum[Min + 1] += -1;
      sum[Max] -= -1;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans += sum[i];
    printf("%lld%c", ans, i == n ? '\n' : ' ');
  }
  return 0;
}
