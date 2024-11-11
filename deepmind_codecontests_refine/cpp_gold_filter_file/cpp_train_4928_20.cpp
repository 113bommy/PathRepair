#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 20, MAXM = 10 * 1000 + 20, INF = 1e9, MOD = 1e9 + 7;
int a[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, b;
  cin >> n >> b >> b;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (a[b - 1] == a[b])
    cout << 0 << endl;
  else
    cout << a[b] - a[b - 1] << endl;
}
