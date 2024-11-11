#include <bits/stdc++.h>
using namespace std;
double eps = 1e-9;
const int INF = 1e9 + 7;
const int MAXN = int(2e5 + 7);
int n, m, k, a[MAXN], mini = INF, ans;
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0) mini = min(mini, a[i]);
  }
  if (n % 2 == 0 || (n + 1) > m * 2) {
    cout << 0;
    return 0;
  }
  cout << min(m * 1ll / ((n + 1) / 2) * k, mini * 1ll) << endl;
  return 0;
}
