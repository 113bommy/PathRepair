#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
long long modInv(long long a) { return binpow(a, MOD - 2); }
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int mxN = 2e5;
int n, m, q, ans;
int arr[2 * mxN + 5][2];
int odd[2 * mxN + 5], even[2 * mxN + 5];
bool greedy(int mid) {
  for (int i = (0); i < (4e5 + 5); i++) {
    odd[i] = 2 * mxN;
    even[i] = 0;
  }
  for (int i = (0); i < (mid); i++) {
    if (arr[i][0] % 2 == 1)
      odd[arr[i][0]] = min(odd[arr[i][0]], arr[i][1]);
    else
      even[arr[i][0]] = max(even[arr[i][0]], arr[i][1]);
  }
  for (int i = (4e5 + 4) - 1; i >= (0); i--)
    even[i] = max(even[i], even[i + 1]);
  for (int i = (0); i < (4e5 + 5); i++)
    if (odd[i] < even[i]) return 0;
  return 1;
}
int bsearch(int lo, int hi) {
  int mid = lo + (hi - lo) / 2;
  if (greedy(mid))
    return bsearch(mid + 1, hi);
  else if (!greedy(mid) && greedy(mid - 1))
    return mid;
  else
    return bsearch(lo, mid - 1);
}
void solve() {
  cin >> n >> m >> q;
  for (int i = (0); i < (q); i++) {
    cin >> arr[i][0];
    cin >> arr[i][1];
  }
  if (greedy(q))
    ans = q + 1;
  else
    ans = bsearch(0, q) - 1;
  for (int i = (0); i < (ans); i++) cout << "YES\n";
  for (int i = (ans); i < (q); i++) cout << "NO\n";
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
