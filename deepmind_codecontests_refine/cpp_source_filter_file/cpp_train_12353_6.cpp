#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
long long ans;
int a[N], n, tr[N];
int lowbit(int first) { return first & -first; }
int sum(int first) {
  int res = 0;
  for (int i = first; i; i -= lowbit(i)) res += tr[i];
  return res;
}
void add(int first, int c) {
  for (int i = first; i <= n; i += lowbit(i)) tr[i] += c;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      que;
  for (int i = 1; i <= n; i++) {
    while (que.size() && que.top().first < i) {
      add(que.top().second, -1);
      que.pop();
    }
    ans += sum(a[i]);
    que.push({a[i], i});
    add(i, 1);
  }
  printf("%lld\n", ans);
  return 0;
}
