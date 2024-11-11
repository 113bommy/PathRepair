#include <bits/stdc++.h>
using namespace std;
class TC {
 public:
  void solve() {
    long long int n, i, j;
    cin >> n;
    long long int a[n];
    long long int fuck = 0;
    for (long long int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    long long int x = 0, sum = 0, m = 100000;
    while (a[x]--) {
      if (x == n) {
        break;
      } else {
        long long int b[a[x] + 1];
        for (j = 0; j < a[x] + 1; j++) {
          cin >> b[j];
          sum += b[j];
        }
        sum = sum * 5 + (a[x] + 1) * 15;
        if (m > sum) {
          m = sum;
        }
        sum = 0;
        x++;
      }
    }
    cout << m << endl;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t = 1, i;
  for (i = 1; i <= t; i++) {
    TC tc;
    tc.solve();
  }
  return 0;
}
