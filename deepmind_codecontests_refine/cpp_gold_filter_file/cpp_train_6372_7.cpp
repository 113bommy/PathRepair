#include <bits/stdc++.h>
const int inf = int(1e9) + 7;
const double eps = 1e-9;
using namespace std;
const int maxn = (2e5 + 10);
char c[30];
bool u[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  string s;
  cin >> n >> k >> s;
  for (int i = 1; i <= k; ++i) cin >> c[i];
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      if (c[j] == s[i]) {
        u[i] = 1;
        break;
      }
    }
  }
  long long res = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (u[i]) {
      cnt++;
    } else {
      res += cnt * (cnt + 1) / 2;
      cnt = 0;
    }
  }
  if (cnt) res += cnt * (cnt + 1) / 2;
  cout << res;
  return 0;
}
