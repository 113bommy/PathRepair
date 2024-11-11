#include <bits/stdc++.h>
using namespace std;
int n, k;
long long sum, ans;
pair<int, int> a[300005];
priority_queue<int, vector<int>, greater<int> > Q;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].second, &a[i].first);
  sort(a + 1, a + n + 1);
  for (int i = n; i >= 1; i--) {
    sum += a[i].second;
    Q.push(a[i].second);
    if (Q.size() == k + 1) {
      sum -= Q.top();
      Q.pop();
    }
    ans = max(ans, a[i].first * sum);
  }
  cout << ans;
  return 0;
}
