#include <bits/stdc++.h>
const int maxn = 1e6 + 1;
const long long mod = 1e9 + 7;
const int base = 1331;
using namespace std;
int n;
int a[maxn];
int ans = 0;
vector<int> divi[200];
void read(void) {
  for (int i = 1; i < 101; i++)
    for (int j = i; j < 101; j += i) divi[j].push_back(i);
  cin >> n;
  for (int i = 1; i <= (int)(n); ++i) cin >> a[i], ans += a[i];
  int res = ans;
  sort(a + 1, a + 1 + n);
  for (int i = (int)(2); i <= (int)(n); ++i) {
    for (int x : divi[a[i]]) {
      res = min(res, ans - a[1] - a[i] + x * a[1] + a[i] / x);
    }
  }
  cout << ans;
}
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  read();
}
