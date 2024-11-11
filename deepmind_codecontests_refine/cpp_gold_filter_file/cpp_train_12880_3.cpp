#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100010;
bool a[maxn];
bool b[maxn];
int32_t main() {
  long long n;
  cin >> n;
  long long temp;
  long long ans = 0;
  for (long long i = 0; i < n; i++) {
    cin >> temp;
    if (temp > 0 && !a[temp]) {
      a[temp] = true;
      ans++;
    }
    if (temp < 0 && !b[-1 * temp]) {
      b[-1 * temp] = true;
      ans++;
    }
  }
  cout << ans << endl;
}
