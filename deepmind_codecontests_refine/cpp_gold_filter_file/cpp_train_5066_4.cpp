#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<long long> d(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &d[i]);
    if (i) d[i] += d[i - 1];
  }
  for (int i = 0; i < m; ++i) {
    long long x;
    scanf("%lld", &x);
    int idx = lower_bound(d.begin(), d.end(), x) - d.begin();
    long long room = x - (idx ? d[idx - 1] : 0);
    printf("%d %lld\n", idx + 1, room);
  }
  return 0;
}
