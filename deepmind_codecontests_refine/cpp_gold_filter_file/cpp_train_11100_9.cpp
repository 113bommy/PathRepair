#include <bits/stdc++.h>
using namespace std;
const long long int p_mod = 9999999999999983;
const long double pi = 3.14159265358979323;
const long long int N = 1e6 + 9;
const long long int mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) {
  uniform_int_distribution<int> uid(l, r);
  return uid(rng);
}
long long int powerk(long long int x, long long int y);
long long int a[N];
map<long long int, long long int> mp;
void solve() {
  long long int n, k, maxm = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    maxm = max(maxm, a[i]);
  }
  if (k > n)
    cout << maxm;
  else {
    long long int cnt = 0, num = a[1];
    for (int i = 2; i <= n; ++i) {
      if (a[i] == maxm) {
        num = maxm;
        break;
      }
      if (a[i] > num) {
        num = a[i];
        cnt = 1;
      } else
        cnt++;
      if (cnt == k) break;
    }
    cout << num;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    solve();
  }
}
long long int powerk(long long int x, long long int y) {
  if (y == 0) return 1;
  if (y == 1) return x % mod;
  if (y & 1)
    return ((powerk((x * x) % mod, y / 2) % mod) * x) % mod;
  else
    return powerk((x * x) % mod, y / 2) % mod;
}
