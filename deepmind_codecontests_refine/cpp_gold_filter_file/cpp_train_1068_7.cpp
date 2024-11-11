#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long inf = 1e18 + 5;
const long long MX = 303030;
int cox[4] = {1, -1, 0, 0};
int coy[4] = {0, 0, 1, -1};
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long leastbit(long long a) { return a & (-a); }
long long C(int a, int b) {
  long long res = 1;
  for (int i = 0; i < b; i++) res = res * (a - i) / (i + 1);
  return res;
}
long long powmod(long long a, long long b) {
  if (b == 0) return 1;
  long long cnt = powmod(a, b / 2);
  (cnt *= cnt) %= mod;
  if (b & 1) {
    (cnt *= a) %= mod;
  }
  return cnt;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, k, arr[105], no = 0, sum = 0, mn = 1000000009, ans = 1000000009;
    set<int> st;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i], st.insert(arr[i]);
    for (int i = 1; i <= n; i++) {
      if ((int(st.size()) + i - 2) / i <= k - 1) {
        ans = i;
        break;
      }
    }
    if (st.size() > 1 && k == 1)
      cout << -1 << endl;
    else if (ans == 1000000009)
      cout << -1 << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
