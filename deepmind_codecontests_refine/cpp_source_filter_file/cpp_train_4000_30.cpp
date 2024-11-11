#include <bits/stdc++.h>
using namespace std;
pair<int, int> num[100005];
bool cmp(pair<int, int> &a, pair<int, int> &b) { return (a.second > b.second); }
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = (1); i <= (m); i += (1)) {
    scanf("%d %d", &num[i].first, &num[i].second);
  }
  sort(num + 1, num + m + 1, cmp);
  int last = 0;
  for (int i = (1); i <= (n); i += (1)) {
    long long step = 1LL * i * (i - 1) / 2;
    if (~i & 1) step += i / 2;
    if (step + 1 <= n)
      last = i;
    else
      break;
  }
  long long ans = 0;
  for (int i = (1); i <= (last); i += (1)) ans += num[i].second;
  printf("%lld\n", ans);
  return 0;
}
