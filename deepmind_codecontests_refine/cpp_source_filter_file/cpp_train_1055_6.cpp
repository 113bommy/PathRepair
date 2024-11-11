#include <bits/stdc++.h>
using namespace std;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long NLINF = 0xf7f7f7f7f7f7f7f7;
const int INF = 0x3f3f3f3f, NINF = 0xf7f7f7f7;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const int N = 3e5 + 10;
int n, k, cur = 0;
pair<int, int> s[N];
long long second[N];
priority_queue<int> pq;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d%d", &s[i].second, &s[i].first);
  sort(s + 1, s + 1 + n);
  long long ans = -1LL, second = 0LL;
  for (int i = n; i >= 1; i--) {
    pq.push(s[i].second);
    if (pq.size() > k) cur = pq.top(), pq.pop();
    second -= cur, second += s[i].second;
    ans = max(ans, s[i].first * 1LL * (second));
  }
  printf("%lld\n", ans);
}
