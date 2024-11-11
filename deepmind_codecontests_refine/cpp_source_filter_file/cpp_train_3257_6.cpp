#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e6;
bool isprime(long long n) {
  if (n % 2 == 0 or n % 3 == 0) {
    return 0;
  }
  if (n == 2 or n == 3) {
    return 1;
  }
  for (long long i = 5; i * i <= n; i += 6) {
    if (n % (i) == 0 or (n % (i + 2)) == 0) {
      return 0;
    }
  }
  return 1;
}
long long findgcd(long long a, long long b) {
  if (a < b) {
    swap(a, b);
  }
  while (a % b) {
    long long rem = a % b;
    a = b;
    b = rem;
  }
  return b;
}
long long findpos(long long v, long long a[], long long n) {
  for (long long i = 0; i < n; i++) {
    if (a[i] == v) {
      return i;
    }
  }
}
void solve() {
  long long n, W;
  cin >> n >> W;
  vector<pair<long long, long long>> a;
  for (long long i = 0; i < n; i++) {
    long long k;
    cin >> k;
    a.push_back({k, i + 1});
  }
  long long k = W / 2;
  for (long long i = 0; i < n; i++) {
    if (a[i].first >= k and a[i].first <= W) {
      cout << 1 << "\n";
      cout << a[i].second << "\n";
      return;
    }
  }
  vector<long long> ans;
  long long sum = 0;
  sort(a.begin(), a.end());
  long long i = n - 1;
  for (i = n - 1; i >= 0; i--) {
    if (a[i].first < k) {
      break;
    }
  }
  if (i == -1) {
    cout << -1 << "\n";
    return;
  }
  while (sum <= k and i >= 0) {
    sum += a[i].first;
    ans.push_back(a[i].second);
    i--;
  }
  if (sum < k and i == -1) {
    cout << -1 << "\n";
    return;
  }
  sort(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
