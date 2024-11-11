#include <bits/stdc++.h>
using namespace std;
void guan() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
const int maxn = 2234567;
const int mod = 1e6 + 3;
const long long MAXX = (1ll << 62) - 1 + (1ll << 62);
long long a[maxn], b[maxn];
void solve(int n, string s) {
  for (int i = 1; i < n; i++) {
    if (s[i] < s[i - 1]) {
      cout << "YES" << endl;
      cout << i << " " << i + 1 << endl;
      return;
    }
  }
  cout << "NO" << endl;
}
int main() {
  guan();
  int T = 1;
  int n, k, m;
  int x;
  string s;
  while (cin >> n >> s) {
    solve(n, s);
  }
  return 0;
}
