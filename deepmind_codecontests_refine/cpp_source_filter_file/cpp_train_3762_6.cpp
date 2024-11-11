#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
const int MOD = 1e9 + 7;
const long double EPS = 1e-10;
const long double PI = acos(-1.0);
int b[100009];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long a[n + 1];
  for (long long i = 1; i <= n; i += 1) cin >> a[i];
  sort(a + 1, a + 1 + n);
  long long ans = 0;
  for (long long i = 1; i <= n; i += 1)
    ans += (a[i] + a[n - i + 1]) * (a[i] + a[n - i + 1]);
  cout << ans << endl;
  return 0;
}
