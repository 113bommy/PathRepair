#include <bits/stdc++.h>
using namespace std;
const long long N = 100010;
const long long INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
long long v[N];
long long st[N];
long long ed[N];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  long long sum = 0;
  long long ok = 1;
  for (long long i = 1; i <= m; i++) {
    cin >> v[i];
    st[i] = i;
    if (v[i] > n - i + 1) ok = 0;
    sum += v[i];
  }
  if (sum < n || !ok) {
    cout << "-1\n";
    return 0;
  }
  long long t = sum - n;
  ed[m] = n;
  st[m] = n - v[m] + 1;
  t -= (v[m] - 1);
  for (long long i = m - 1; i >= 1; i--) {
    if (t == 0) break;
    ed[i] = st[i + 1] - 1;
    if (t >= (v[i] - 1)) {
      st[i] = ed[i] - v[i] + 1;
      t -= (v[i] - 1);
    } else {
      st[i] = ed[i] - t;
      break;
    }
  }
  for (long long i = 1; i <= m; i++) {
    cout << st[i] << " ";
  }
  cout << "\n";
}
