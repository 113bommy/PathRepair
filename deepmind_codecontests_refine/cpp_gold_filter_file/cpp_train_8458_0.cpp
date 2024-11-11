#include <bits/stdc++.h>
using namespace std;
inline int readint() {
  int res = 0;
  char c = 0;
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) res = res * 10 + c - '0', c = getchar();
  return res;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  long long a[n * 2 + 1];
  for (long long i = 1; i <= n * 2; i++) cin >> a[i];
  map<long long, long long> c;
  for (long long i = 1; i <= n * 2; i++) {
    c[a[i]]++;
    if (c[a[i]] == 2) cout << a[i] << " ";
  }
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
