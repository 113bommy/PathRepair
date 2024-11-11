#include <bits/stdc++.h>
using namespace std;
long long l[200010], t[200010];
const int MX = 200010;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, r, ans = 0;
  cin >> n >> r;
  for (int i = 0, ggdem = n; i < ggdem; i++) cin >> l[i];
  for (int i = 0, ggdem = n; i < ggdem; i++) cin >> t[i];
  for (int i = 0, ggdem = n; i < ggdem; i++)
    if (t[i] < l[i]) cout << "-1\n", exit(0);
  long long rem = 0, tim = 0;
  vector<long long> res;
  for (int i = 0, ggdem = n; i < ggdem; i++) {
    if (rem >= l[i]) {
      rem -= l[i];
      tim += l[i];
      continue;
    }
    l[i] -= rem;
    t[i] -= rem;
    tim += rem;
    long long must = max(0ll, 2 * l[i] - t[i]);
    long long reps = (must + r - 1) / r;
    long long fir = tim + 2ll * (t[i] - l[i]);
    tim = fir;
    for (int i = 0, ggdem = reps; i < ggdem; i++) {
      if (((int)(res).size()) == MX) break;
      res.push_back(fir);
      fir += r;
    }
    tim += must;
    ans += reps;
    rem = r * reps - must;
  }
  assert(ans >= 0);
  cout << ans << "\n";
  if (((int)(res).size()) <= 1e5) {
    for (auto x : res) cout << x << " ";
    cout << "\n";
  }
}
