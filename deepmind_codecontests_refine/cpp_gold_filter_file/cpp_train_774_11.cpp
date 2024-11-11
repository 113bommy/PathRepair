#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 2;
using ll = long long;
int freq[MAXN];
ll dp[MAXN];
int main() {
  int n, m;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int p1 = 0, p2 = 0, ans = 0;
  while (p1 < n && p2 < m) {
    if (abs(a[p1] - b[p2]) <= 1) {
      p1++;
      p2++;
      ans++;
    } else if (a[p1] > b[p2]) {
      p2++;
    } else
      p1++;
  }
  cout << ans << endl;
  return 0;
}
