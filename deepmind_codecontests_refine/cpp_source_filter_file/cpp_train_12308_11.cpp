#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
pair<int, int> a[N];
int n;
set<int> S;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].first);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i].second);
  sort(a + 1, a + n + 1);
  int ptr = 1, cur = a[1].first;
  long long ans = 0, sum = 0;
  while (ptr <= n || S.size()) {
    if (!S.size()) cur = a[ptr].first;
    while (cur == a[ptr].first && ptr <= n) {
      S.insert(a[ptr].second);
      sum += a[ptr].second;
      ptr++;
    }
    auto it = S.end();
    it--;
    int t = *it;
    S.erase(it);
    sum -= t;
    ans += sum;
    cur++;
  }
  printf("%lld\n", ans);
  return 0;
}
