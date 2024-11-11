#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e6;
const long long MOD = 1e9 + 7;
const long long N = 1e6 + 7;
const long long N_N = 1e3;
const int INF = 1e9 + 228;
const long double eps = 1e-12;
long long n, m, a[N], res, cnt, ans;
string s, t;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == 100) ans++;
    if (a[i] == 200) res++;
  }
  if ((ans == 0 && res % 2 != 0) || (res == 0 && ans % 2 != 0)) {
    cout << "NO";
    return 0;
  }
  if ((ans % 2 == 0 && res % 2 == 0) || (ans % 2 == 0 && res % 2 != 0)) {
    cout << "YES";
    return 0;
  } else
    cout << "NO";
  return 0;
}
