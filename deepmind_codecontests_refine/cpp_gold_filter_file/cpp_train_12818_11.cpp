#include <bits/stdc++.h>
using namespace std;
int ar[200005], col[200005];
int cnt[200005];
int main() {
  long long t, n, m, i, ans = 0, mx = 0, k;
  cin >> n >> m >> k;
  for (i = 0; i < n; i++) {
    cin >> ar[i];
    if (ar[i] <= m) {
      mx++;
    }
  }
  if (m > k)
    cout << n << endl;
  else
    cout << (mx + 1) / 2 << endl;
}
