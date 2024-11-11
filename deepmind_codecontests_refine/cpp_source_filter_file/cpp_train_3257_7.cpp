#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1000005;
const long long SQRTN = 1003;
const long long LOGN = 22;
const double PI = acos(-1);
const long long INF = 1e18;
const long long MOD = 1000000007;
const long long FMOD = 998244353;
const double eps = 1e-9;
long long ceil_division(long long a, long long b) { return (a + b - 1) / b; }
void solvethetestcase() {
  long long n;
  float w;
  cin >> n >> w;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long c = 0;
  for (long long i = 0; i < n; i++) {
    if (a[i] <= w && a[i] >= ceil_division(w, 2)) {
      cout << 1 << "\n";
      cout << i + 1 << "\n";
      return;
    }
    if (a[i] > w) {
      c++;
    }
  }
  if (c == n) {
    cout << -1 << "\n";
    return;
  }
  pair<long long, long long> p[n];
  for (long long i = 0; i < n; i++) {
    p[i].first = a[i];
    p[i].second = i;
  }
  sort(p, p + n);
  long long s = 0;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    s += p[i].first;
    v.push_back(p[i].second);
    if (s >= ceil_division(w, 2) && s <= w) {
      cout << v.size() << "\n";
      for (long long j = 0; j < v.size(); j++) {
        cout << v[j] + 1 << " ";
      }
      cout << "\n";
      return;
    }
  }
  cout << -1 << "\n";
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long testcase = 1; testcase < t + 1; testcase++) {
    solvethetestcase();
  }
}
