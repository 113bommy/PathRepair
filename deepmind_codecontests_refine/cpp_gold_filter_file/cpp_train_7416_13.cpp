#include <bits/stdc++.h>
using namespace std;
long long n;
long long calcCards(long long x) { return x * (x + 1) + (x - 1) * x / 2; }
bool P(int x) { return calcCards(x) <= n; }
long long bs(long long l = 0, long long h = n) {
  long long m;
  while (l < h) {
    m = (l + h + 1) / 2;
    if (P(m))
      l = m;
    else
      h = m - 1;
  }
  return l;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int ans = 0;
    while (n >= 2) {
      ans++;
      n -= calcCards(bs());
    }
    cout << ans << endl;
  }
}
