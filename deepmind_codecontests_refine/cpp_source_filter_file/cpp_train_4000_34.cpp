#include <bits/stdc++.h>
using namespace std;
const static int INF = 1e8;
const static double EPS = 1e-8;
long long eval(long long a) {
  if (a & 1LL)
    return a * (a - 1) + 1;
  else
    return a * (a - 1) + a / 2;
}
int main() {
  int n, m, dummy;
  scanf("%d%d", &n, &m);
  vector<int> w(m);
  for (int i = 0; i < (int)(m); i++) scanf("%d%d", &dummy, &w[i]);
  sort((w).begin(), (w).end());
  reverse((w).begin(), (w).end());
  long long l = 1, r = m + 1;
  while (r - l > 1) {
    long long mean = (l + r) / 2;
    if (eval(mean) <= n)
      l = mean;
    else
      r = mean;
  }
  long long ans = 0;
  for (int i = 0; i < (int)(l); i++) ans += w[i];
  cout << ans << endl;
}
