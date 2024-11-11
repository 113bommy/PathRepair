#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 7, inf = 1e18 + 7, mod = 1e9 + 7;
long long tc, n, m, q, a, b, c, d, i, j, k, l, id, sum, cnt, ans, tmp, flag, mn,
    mx;
long long ar[N];
string s;
vector<long long> v;
int main() {
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a, v.push_back(a);
  sort(v.begin(), v.end());
  for (i = 0, j = n / 2; j < n; j++) {
    if (v[j] - v[i] >= m) cnt++, i++, ar[j] = 1;
  }
  cout << cnt << endl;
}
