#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1.5e6 + 5;
const int MAXM = 1.5e6 + 5;
std::vector<int> v[MAXM];
std::vector<int> G[MAXM];
int a[MAXM], b[MAXM];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) cin >> b[i], b[i] += b[i - 1];
  if (a[n] != b[m]) return puts("-1"), 0;
  long long suma = 0, sumb = 0, k = 1, ans = 0;
  for (int i = 1; i <= n; i++) {
    suma = a[i];
    while (suma > sumb) sumb = b[k++];
    if (suma == sumb) ans++;
  }
  cout << ans << endl;
  return 0;
}
