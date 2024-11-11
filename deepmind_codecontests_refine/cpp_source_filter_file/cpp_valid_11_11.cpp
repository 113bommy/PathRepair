#include <bits/stdc++.h>
using namespace std;
long long const mod = 1000000007LL;
long long const mod2 = 100000000LL;
long long const md = 998244353LL;
long long mypowr(long long a, long long b) {
  long long res = 1;
  if (b < 0) b = 0;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long mypow(long long a, long long b) {
  long long res = 1;
  if (b < 0) b = 0;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a;
    a = a * a;
  }
  return res;
}
ifstream in("input.txt");
ofstream out("output.txt");
const long long infll = 9e18;
const int inf = 2e9;
const long long maxn = 2e5 + 2;
string s[maxn];
vector<int> v;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
  int test = 1;
  cin >> test;
  while (test--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      cin >> s[i];
    }
    int cnt = 0;
    for (int i = 0; i < 4; ++i) {
      char c = 'a' + i;
      for (int j = 1; j <= n; ++j) {
        int a = 0, u = s[j].size();
        for (int t = 0; t < u; ++t) {
          if (s[j][t] == c)
            ++a;
          else
            --a;
        }
        v.push_back(a);
      }
      sort(v.rbegin(), v.rend());
      int y = v.size();
      int sum = 0, mx = 0;
      for (int j = 0; j < y; ++j) {
        sum += v[j];
        if (sum <= 0) {
          j = y + 1;
          continue;
        }
        ++mx;
      }
      cnt = max(cnt, mx);
      v.clear();
    }
    cout << cnt << '\n';
  }
  return 0;
}
