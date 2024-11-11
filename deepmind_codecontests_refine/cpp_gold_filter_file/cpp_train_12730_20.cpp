#include <bits/stdc++.h>
using namespace std;
bool isPowerOfTwo(int x) { return x && !(x & (x - 1)); }
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n, 1);
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
