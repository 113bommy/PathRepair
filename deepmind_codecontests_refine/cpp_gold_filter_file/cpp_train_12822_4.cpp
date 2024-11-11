#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int main() {
  long long n, k;
  int m;
  scanf("%lld %d %lld", &n, &m, &k);
  vector<long long> p(m);
  for (int i = 0; i < m; i++) {
    scanf("%lld", &p[i]);
    --p[i];
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    long long pn = (p[i] - i) / k;
    int now = i;
    while (now < m and (p[now] - i) / k <= pn) {
      ++now;
    }
    ++ans;
    i = now - 1;
  }
  printf("%d\n", ans);
  return 0;
}
