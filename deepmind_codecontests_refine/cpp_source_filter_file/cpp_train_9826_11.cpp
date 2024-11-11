#include <bits/stdc++.h>
using namespace std;
const int ppr = 257;
const long long INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const int N = 1e6 + 123;
const long double pi = 3.141592653589793238462643;
long long n, b[20][N], c[N], ans, cz;
void add(long long x) {
  long long v = 0;
  for (long long i = 17; i >= 0; i--) {
    long long bit = (x & (1 << i));
    if (bit) bit = 1;
    if (!b[bit][v]) b[bit][v] = ++cz;
    v = b[bit][v];
    c[v]++;
  }
}
void erase(long long x) {
  long long v = 0;
  for (long long i = 17; i >= 0; i--) {
    long long bit = (x & (1 << i));
    if (bit) bit = 1;
    v = b[bit][v];
    c[v]--;
  }
}
long long get(long long x) {
  long long v = 0, ans = 0;
  for (long long i = 17; i >= 0; i--) {
    long long bit = (x & (1 << i));
    if (bit) bit = 1;
    if (b[bit ^ 1][v] && c[b[bit ^ 1][v]]) {
      ans += (1 << i);
      v = b[bit ^ 1][v];
    } else {
      v = b[bit][v];
    }
  }
  return ans;
}
long long a[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long i = 0; i <= n; i++) add(i);
  for (long long i = n; i >= 0; i--) {
    long long x = get(i);
    ans += x;
    a[x ^ i] = i;
    erase(x ^ i);
  }
  cout << ans << '\n';
  for (long long i = 0; i <= n; i++) cout << a[i] << ' ';
  return 0;
}
