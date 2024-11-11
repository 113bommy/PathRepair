#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long dx[4] = {-1, 1, 0, 0};
const long long dy[4] = {0, 0, -1, 1};
const long long MAX = 1e6 + 5;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long n, m, k, q;
string second;
map<long long, long long> lvl;
vector<long long> v;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  long long maxi = 0;
  long long alls = 0;
  for (int i = 1; i <= n; i++) cin >> k, v.push_back(k), alls += k;
  sort(v.begin(), v.end());
  long long ans = 0;
  long long cur = 0;
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, v[i]);
    if (v[i] >= cur + 1) cur++;
  }
  cout << alls - maxi + cur - n;
  return 0;
}
