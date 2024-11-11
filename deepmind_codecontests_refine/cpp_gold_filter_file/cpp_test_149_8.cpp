#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const long long MAX = 3e5 + 10;
const long long Time = 86400;
const long long X = 131;
const long long inf = 0x3f3f3f3f;
const double PI = 1e-4;
double pai = 3.14159265358979323846;
long long T, n, m, k, x, ans;
string s;
long long a[MAX];
vector<long long> v;
char ch;
void solve() {
  v.clear();
  cin >> n >> k >> x;
  for (long long i = 1; i <= n; i++) {
    cin >> ch;
    if (ch == 'a')
      v.push_back(-1);
    else {
      if (v.empty() || v.back() == -1)
        v.push_back(k);
      else
        v.back() += k;
    }
  }
  a[v.size()] = 1;
  for (long long i = v.size() - 1; i >= 0; i--) {
    if (v[i] == -1) {
      a[i] = a[i + 1];
      continue;
    }
    if ((double)a[i + 1] * (v[i] + 1) > 2e18)
      a[i] = 2e18;
    else
      a[i] = a[i + 1] * (v[i] + 1);
  }
  for (long long i = 0; i < v.size(); i++) {
    if (v[i] == -1)
      cout << "a";
    else {
      while (x > a[i + 1]) cout << "b", x -= a[i + 1];
    }
  }
  cout << "\n";
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
