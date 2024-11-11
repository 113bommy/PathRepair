#include <bits/stdc++.h>
using namespace std;
const long long N = 200100;
long long ans;
vector<long long> a(N), b(N), m(N), ans1(N), ans2(N);
void cal(vector<long long>& ind) {
  long long n = (long long)ind.size();
  long long l = -1, r = -1, prev = 0;
  for (long long j = 0; j < n; j++) {
    long long i = ind[j];
    long long lx = max(0LL, a[i] - m[i]);
    long long rx = max(0LL, a[i]);
    long long templ = l, tempr = r;
    if ((l == -1) || (l < lx)) {
      l = lx;
    }
    if ((r == -1) || (rx < r)) {
      r = rx;
    }
    if (l > r) {
      ans -= (j - prev - 1);
      long long to = templ;
      for (long long k = prev; k < j; k++) {
        i = ind[k];
        ans1[i] = a[i] - to;
        ans2[i] = m[i] - ans1[i];
      }
      prev = j;
      j--;
      l = -1, r = -1;
    } else if (j == n - 1) {
      ans -= (j - prev + 1 - 1);
      long long to = l;
      for (long long k = prev; k <= j; k++) {
        i = ind[k];
        ans1[i] = a[i] - to;
        ans2[i] = m[i] - ans1[i];
      }
    }
  }
}
void solve() {
  long long n;
  cin >> n;
  ans = n;
  map<long long, vector<long long>> mp;
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> m[i];
    mp[a[i] + b[i] - m[i]].push_back(i);
  }
  for (auto& p : mp) {
    sort(p.second.begin(), p.second.end(),
         [&](const long long& i1, const long long& i2) {
           if (a[i1] != a[i2]) {
             return a[i1] < a[i2];
           }
           return b[i1] < b[i2];
         });
    cal(p.second);
  }
  cout << ans << '\n';
  for (long long i = 0; i < n; i++) {
    cout << ans1[i] << ' ' << ans2[i] << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
