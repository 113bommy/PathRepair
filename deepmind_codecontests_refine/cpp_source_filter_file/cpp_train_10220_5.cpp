#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long i, j, k, l = 0, m, n;
    cin >> n >> k;
    long long ara[n];
    for (i = 0; i < n; i++) cin >> ara[i];
    sort(ara, ara + n);
    for (i = 0; i < n; i++) {
      if (ara[i] <= ara[0] + k)
        continue;
      else if ((ara[i] > ara[0] + k) && ara[i] - k <= ara[0] + k)
        continue;
      else {
        cout << -1 << endl;
        l++;
        break;
      }
    }
    if (l > 0) cout << ara[0] + k << endl;
  }
  return 0;
}
