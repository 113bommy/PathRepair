#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const double PI = acos(-1);
int n, k, a[MAXN];
map<int, int> m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    m[a[i]]++;
  }
  if (m[a[k]] == n) {
    cout << 0 << "\n";
    return 0;
  }
  for (int i = k; i <= n; ++i) {
    if (a[i] != a[k]) {
      cout << -1 << "\n";
      return 0;
    }
  }
  int last = INF;
  for (int i = 1; i < k; ++i) {
    if (a[i] != a[k]) last = i;
  }
  cout << min(last, k - 1) << "\n";
  return 0;
}
