#include <bits/stdc++.h>
using namespace std;
int pos[100005], a[100005], b[100005], n;
multiset<int> s;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) pos[a[i]] = i;
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) s.insert(i - pos[b[i]]);
  for (int i = 0; i <= n - 1; i++) {
    multiset<int>::iterator it = s.lower_bound(i);
    int ans = 914990825;
    if (it != s.end()) ans = min(ans, (*it) - i);
    if (it != s.begin()) ans = min(ans, i - (*(--it)));
    printf("%d\n", ans);
    s.erase(i + 1 - pos[b[i + 1]]);
    s.insert(i + n + 1 - pos[b[i + 1]]);
  }
  return 0;
}
