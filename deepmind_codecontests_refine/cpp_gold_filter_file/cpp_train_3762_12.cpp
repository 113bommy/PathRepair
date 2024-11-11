#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 7;
int n, m;
long long a[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  long long ans = 0;
  for (int i = (1); i <= (n / 2); ++i) {
    ans += (a[i] + a[n - i + 1]) * (a[i] + a[n - i + 1]);
  }
  cout << ans << '\n';
}
