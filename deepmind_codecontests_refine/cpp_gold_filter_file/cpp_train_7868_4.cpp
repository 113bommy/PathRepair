#include <bits/stdc++.h>
using namespace std;
const long long maxn = 128000;
long long a[maxn];
long long n;
set<long long> q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  long long sum = 0;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  long long s1 = 0;
  string ans = "NO";
  for (long long i = 0; i < n; ++i) {
    s1 += a[i];
    q.insert(a[i]);
    long long s2 = sum - s1;
    if (s1 > s2) {
      auto el = q.lower_bound((s1 - s2) / 2);
      if (el != q.end() && (s1 - s2) % 2 == 0 && *el == (s1 - s2) / 2) {
        ans = "YES";
      }
    }
  }
  while (!q.empty()) q.erase(q.begin());
  for (long long i = 0; i < n / 2; ++i) swap(a[i], a[n - i - 1]);
  s1 = 0;
  for (long long i = 0; i < n; ++i) {
    s1 += a[i];
    q.insert(a[i]);
    long long s2 = sum - s1;
    if (s1 > s2) {
      auto el = q.lower_bound((s1 - s2) / 2);
      if (el != q.end() && (s1 - s2) % 2 == 0 && *el == (s1 - s2) / 2) {
        ans = "YES";
      }
    }
  }
  cout << ans << endl;
  return 0;
}
