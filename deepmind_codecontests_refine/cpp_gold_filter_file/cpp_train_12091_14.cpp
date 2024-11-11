#include <bits/stdc++.h>
using namespace std;
const int MAX = 200010;
const long long MOD = (int)1e9 + 7;
const int INF = 1e9;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-8;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> v(n);
  for (int i = 0; i < (int)n; i++) {
    cin >> v[i];
  }
  sort(v.rbegin(), v.rend());
  long long soma = k * v[0] + v[1];
  long long qt = m / (k + 1);
  long long res = qt * soma;
  m -= qt * (k + 1);
  res += m * v[0];
  cout << res << '\n';
  return 0;
}
