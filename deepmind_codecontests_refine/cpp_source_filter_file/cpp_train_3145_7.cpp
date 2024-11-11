#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rnd64(
    chrono::high_resolution_clock::now().time_since_epoch().count());
long long power(long long a, long long m, long long mod) {
  long long ans = 1;
  while (m) {
    if (m % 2) {
      ans *= a;
      ans %= (mod);
    }
    a = (a * a) % (mod);
    m >>= 1;
  }
  return ans;
}
void init(long long* a, long long n, long long val) {
  for (long long i = 0; i < n; i++) a[i] = val;
}
void solve() {
  long long i, j, _, n, ans = 0, c = 1, ind;
  cin >> n;
  long long a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == -1) ind = i;
  }
  reverse(a, a + n);
  ind = n - ind - 1;
  long long k = n / 2;
  set<long long> st;
  for (i = 0; i < ind + 1; i++) {
    if (c) {
      st.insert(a[i]);
      --c;
    } else {
      ans += (*(st.begin()));
      st.erase(st.begin());
      st.insert(a[i]);
      c = k - 1;
      k /= 2;
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
