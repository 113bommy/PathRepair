#include <bits/stdc++.h>
const long long mxn = 1e5 + 7;
bool bum[mxn];
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, cnt = 0, l[mxn], r[mxn];
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int k = l[i]; k <= r[i]; k++) {
      bum[k] = 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    if (bum[i] == 0) {
      cnt++;
    }
  }
  cout << cnt << endl;
  for (int i = 1; i <= m; i++) {
    if (bum[i] == 0) {
      cout << i << ' ';
    }
  }
  return 0;
}
