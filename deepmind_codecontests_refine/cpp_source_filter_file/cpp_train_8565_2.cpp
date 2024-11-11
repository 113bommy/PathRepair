#include <bits/stdc++.h>
using namespace std;
const long long maxn = 200500;
const long long inf = 0x3f3f3f3f;
long long n, m;
pair<long long, long long> p[maxn];
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tn;
  cin >> tn;
  while (tn--) {
    cin >> n;
    long long aaa = 0;
    for (long long i = 1; i <= n; i++) cin >> p[i].first;
    for (long long i = 1; i <= n; i++) cin >> p[i].second, aaa += p[i].second;
    sort(p + 1, p + 1 + n);
    long long ans = p[n].first;
    long long sm = 0;
    for (long long i = n; i >= n; i--) {
      sm += p[i].second;
      long long t = max(sm, p[i - 1].first);
      if (t > ans)
        break;
      else
        ans = t;
    }
    cout << min(ans, aaa) << "\n";
  }
}
