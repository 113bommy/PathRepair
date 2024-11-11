#include <bits/stdc++.h>
using namespace std;
const long long int moddd = 1e9 + 7;
long long int poww(long long int x, long long int n) {
  long long int res = 1;
  while (n > 0) {
    if (n % 2) res *= x;
    n = n >> 1;
    x *= x;
  }
  return res;
}
long long int check(vector<long long int> &arr, long long int mid) {
  vector<long long int> pref(arr.size(), 0);
  for (int i = 0; i < arr.size(); ++i) {
    pref[i] = arr[i] + (i + 1) * 1LL * mid;
  }
  sort(pref.begin(), pref.end());
  long long int f = 0;
  for (int i = 0; i < mid; i++) f += pref[i];
  return f;
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long int lo = 0, hi = n + 1;
  while (lo < hi) {
    long long int mid = (lo + hi + 1) / 2;
    if (check(a, mid) <= k)
      lo = mid;
    else
      hi = mid - 1;
  }
  cout << lo << " " << check(a, lo);
}
int main() {
  ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  ;
  { solve(); }
}
