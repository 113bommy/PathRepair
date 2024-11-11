#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5;
int main(void) {
  int n, k;
  pair<int, pair<int, int> > a[N];
  long long ans[N];
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i].first);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].second.first);
    a[i].second.second = i;
  }
  sort(a, a + n);
  long long sum = 0LL;
  multiset<int> cur;
  for (int i = 0; i < n; i++) {
    int cur_money = a[i].second.first;
    int ind = a[i].second.second;
    ans[ind] = sum + (long long)cur_money;
    if ((int)cur.size() < k) {
      cur.insert(cur_money);
      sum += (long long)cur_money;
    } else if (k > 0 && (*cur.begin()) < cur_money) {
      sum -= (long long)*cur.begin();
      sum += (long long)cur_money;
      cur.erase(cur.begin());
      cur.insert(cur_money);
    }
  }
  for (int i = 0; i < n; i++) printf("%I64d ", ans[i]);
  return 0;
}
