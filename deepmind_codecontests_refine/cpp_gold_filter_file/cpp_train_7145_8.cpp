#include <bits/stdc++.h>
using namespace std;
const long long INF = 4000000000000000000LL;
int main() {
  long long n, l;
  scanf("%lld %lld", &n, &l);
  vector<int> cost(n);
  for (int i = 0; i <= n - 1; i++) {
    scanf("%d", &cost[i]);
  }
  for (int i = 1; i <= n - 1; i++) {
    cost[i] = min(cost[i], 2 * cost[i - 1]);
  }
  long long sum = 0, ans = INF;
  for (int i = n - 1; i >= 0; i--) {
    long long val = (1 << (i));
    long long times = l / val;
    sum += times * cost[i];
    l -= times * val;
    ans = min(ans, sum + cost[i]);
  }
  ans = min(ans, sum);
  cout << ans << endl;
}
