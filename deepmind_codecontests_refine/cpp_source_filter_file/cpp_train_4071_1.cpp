#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 5;
const long long INF = 1e18 + 7;
long long n, m, ans = INF;
deque<long long> a[N], b[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    a[x].push_back(y);
  }
  for (long long i = 1; i <= n; i++) sort(a[i].begin(), a[i].end());
  for (long long i = 1; i <= n; i++) {
    long long s = 0, Count = a[1].size();
    for (long long j = 1; j <= m; j++) b[j] = a[j];
    for (long long j = 2; j <= m; j++) {
      while (b[j].size() >= i) {
        s += b[j].front();
        b[j].pop_front();
        Count++;
      }
    }
    deque<long long> V;
    V.clear();
    for (long long j = 2; j <= m; j++)
      for (auto it : b[j]) V.push_back(it);
    sort(V.begin(), V.end());
    while (Count < i) {
      if (V.empty()) break;
      s += V.front();
      V.pop_front();
      Count++;
    }
    if (Count >= i) ans = min(ans, s);
  }
  cout << ans;
  return 0;
}
