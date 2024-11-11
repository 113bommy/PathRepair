#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 7;
const long long INF = 1e18;
const long long MOD = 1e9 + 7;
long long n, m;
long long a[N];
long long b[N];
bool f(long long op) {
  long long prev = 0;
  for (long long i = 0; i < n; i++) {
    if (prev <= a[i]) {
      long long k = m - a[i] + prev;
      if (k > op) prev = a[i];
    } else {
      long long k = prev - a[i];
      if (k > op) return false;
    }
  }
  return true;
}
void solve() {
  cin >> n >> m;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long lo = 0, hi = INF;
  while (lo < hi) {
    long long m = (lo + hi) / 2;
    if (f(m))
      hi = m;
    else
      lo = m + 1;
  }
  cout << lo << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t beg = clock();
  long long t = 1;
  while (t--) {
    solve();
  }
  cerr << "\nExecution time: " << (clock() - beg) / 1000 << '\n';
}
