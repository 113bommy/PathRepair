#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using mpii = map<int, int>;
using si = set<int>;
using sll = set<ll>;
using vll = vector<ll>;
int ar[300010], ans[300010];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &ar[i]);
  }
  priority_queue<pair<int, int>> que;
  ll sum = 0;
  for (int i = 1; i <= k; i++) que.push(make_pair(ar[i], i));
  for (int i = k + 1; i <= k + n; i++) {
    if (i <= n) que.push(make_pair(ar[i], i));
    ans[que.top().second] = i;
    sum += 1LL * (i - que.top().second) * que.top().first;
    que.pop();
  }
  printf("%lld", sum);
  printf("\n");
  for (int i = 1; i <= n; i++) {
    printf("%d", ans[i]);
    printf(" ");
  }
  printf("\n");
  return 0;
}
