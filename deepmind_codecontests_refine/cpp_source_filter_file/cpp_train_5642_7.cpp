#include <bits/stdc++.h>
namespace ZZ {
const long double PI = acos(-1);
using namespace std;
void invec(vector<long long> &a, long long n) {
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
}
long long gcnt = 0, gmax = INT_MIN, gmin = INT_MAX;
}  // namespace ZZ
using namespace ZZ;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long tcs;
  cin >> tcs;
  while (tcs--) {
    long long n, k, d;
    cin >> n >> k >> d;
    vector<long long> a(n);
    invec(a, n);
    if (n == d) {
      cout << n << "\n";
      ;
      continue;
    }
    long long i = 0, j = d - 1;
    map<long long, long long> m;
    for (long long k = 0; k <= j; k++) {
      m[a[k]]++;
    }
    long long mn = m.size();
    while (j < n) {
      m[a[j + 1]]++;
      m[a[i]]--;
      if (m[a[i]] == 0) m.erase(m.find(a[i]));
      mn = min(mn, (long long)m.size());
      i++;
      j++;
    }
    cout << mn << "\n";
    ;
  }
}
