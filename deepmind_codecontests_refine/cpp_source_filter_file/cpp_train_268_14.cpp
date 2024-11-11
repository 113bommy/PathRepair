#include <bits/stdc++.h>
using namespace std;
const int Maxn = 3e5 + 10;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-8;
const double PI = acos(-1);
int n, k, m;
long long t[Maxn], sum = 0;
long long cal(int x) {
  if (m < x * sum) return 0;
  long long ans = x * (k + 1);
  long long yu = m - x * sum;
  for (int i = 1; i <= k; i++)
    for (int j = x; j < n; j++)
      if (t[i] <= yu)
        yu -= t[i], ans++;
      else
        return ans;
  return ans;
}
int main() {
  long long ans = 0;
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= k; i++) scanf("%I64d", &t[i]), sum += t[i];
  sort(t + 1, t + n + 1);
  for (int i = 0; i <= n; i++) ans = max(ans, cal(i));
  printf("%I64d\n", ans);
  return 0;
}
