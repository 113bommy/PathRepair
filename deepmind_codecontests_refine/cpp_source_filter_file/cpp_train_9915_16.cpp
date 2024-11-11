#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 7;
long long modexp(long long a, long long b, long long m) {
  long long r = 1;
  a = a % m;
  while (b > 0) {
    if (b & 1) r = (r * a) % m;
    b = b / 2;
    a = (a * a) % m;
  }
  return r % m;
}
bool cmp(pair<long long, long long>& a, pair<long long, long long>& b) {
  if (a.second != b.second) return a.second > b.second;
  return a.first > b.first;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    vector<long long> p(n, 0);
    for (long long i = 1; i < n - 1; i++) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1]) p[i]++;
    }
    for (long long i = 1; i < n; i++) p[i] += p[i - 1];
    long long m = 0;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      long long r = i + k - 1;
      if (r >= n) break;
      if (p[r - 1] - p[i] > m) {
        m = p[r - 1] - p[i];
        ans = i + 1;
      }
    }
    cout << m + 1 << " " << ans << endl;
  }
}
