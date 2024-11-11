#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5e5 + 5;
vector<long long> a, b;
long long solve() {
  a.clear();
  b.clear();
  long long n, m;
  cin >> n >> m;
  while (n--) {
    long long e;
    cin >> e;
    if (e > 0)
      a.push_back(e);
    else if (e < 0)
      b.push_back(-e);
  }
  a.push_back(0);
  b.push_back(0);
  sort(a.begin(), a.end(), greater<long long>());
  sort(b.begin(), b.end(), greater<long long>());
  long long ans = a[0] + b[0];
  long long have = m - 1;
  for (long long i = 1; i < a.size(); ++i) {
    if (have == 0) {
      have = m;
      ans += 2 * a[i];
    }
    have--;
  }
  have = m - 1;
  for (long long i = 1; i < b.size(); ++i) {
    if (have == 0) {
      have = m;
      ans += 2 * b[i];
    }
    have--;
  }
  if (a[0] < b[0])
    ans += a[0];
  else
    ans += 2 * b[0];
  return ans;
}
signed main() {
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }
}
