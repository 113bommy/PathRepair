#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int a[N], b[N], c[N], l[N], r[N], d[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, m, k, x, y;
  cin >> n >> m >> k;
  for (long long int i = (1); i <= (n); ++i) cin >> a[i];
  for (long long int i = (1); i <= (m); ++i) cin >> l[i] >> r[i] >> d[i];
  for (long long int i = (1); i <= (k); ++i) {
    cin >> x >> y;
    c[x]++;
    c[y + 1]--;
  }
  for (long long int i = (1); i <= (k); ++i) {
    c[i] = c[i] + c[i - 1];
  }
  for (long long int i = (1); i <= (m); ++i) {
    b[l[i]] += c[i] * d[i];
    b[r[i] + 1] -= c[i] * d[i];
  }
  for (long long int i = (1); i <= (n); ++i) {
    b[i] = b[i - 1] + b[i];
  }
  for (long long int i = (1); i <= (n); ++i) {
    a[i] = a[i] + b[i];
    cout << a[i] << " ";
  }
  cout << "\n";
  return 0;
}
