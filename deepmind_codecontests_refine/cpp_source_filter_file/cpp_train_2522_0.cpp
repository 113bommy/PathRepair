#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
const int INF = 0x3f3f3f3f;
const int NINF = -INF - 1;
const double PI = acos(-1);
const int mod = 1e9 + 7;
const int maxn = 4e4 + 5;
using namespace std;
int cnta[maxn], cntb[maxn];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int temp1 = 0, temp2 = 0;
  for (int i = (1); i <= (n); i++) {
    int a;
    cin >> a;
    if (a)
      cnta[temp1]++;
    else
      temp1++;
  }
  for (int i = (1); i <= (m); i++) {
    int b;
    cin >> b;
    if (b)
      cntb[temp2]++;
    else
      temp2++;
  }
  long long ans = 0, cnt1, cnt2;
  for (int i = (1); i <= (sqrt(k)); i++) {
    if (k % i == 0 && k / i <= 40000) {
      cnt1 = cnt2 = 0;
      for (int j = (0); j <= (temp1); j++) {
        if (cnta[j] >= i) cnt1 += cnta[j] - i + 1;
      }
      for (int j = (0); j <= (temp2); j++) {
        if (cntb[j] >= k / i) cnt2 += cntb[j] - k / i + 1;
      }
      ans += cnt1 * cnt2;
    }
  }
  cout << ans << '\n';
  return 0;
}
