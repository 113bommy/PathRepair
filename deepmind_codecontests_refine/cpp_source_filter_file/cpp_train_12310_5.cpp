#include <bits/stdc++.h>
using namespace std;
long long Log = 30;
const long long mod = (long long)1e9 + 7;
const long long inf = (long long)2242545357980376863;
const int e6 = 1e6;
const int e2_5 = 2e5;
const int M = 1e6 + 20;
const int N = 30 + 20;
int t, n, k, a[N], b[N], tmp, sum;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    tmp = 0;
    sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    sort(a, a + n);
    reverse(a, a + n);
    sort(b, b + n);
    reverse(b, b + n);
    int i = 0, j = 0;
    while (1) {
      if (a[i] >= b[i]) {
        sum += a[i];
        tmp++;
        i++;
      } else if (k > 0) {
        sum += b[j];
        tmp++;
        j++;
        k--;
      } else {
        sum += a[i];
        tmp++;
        i++;
      }
      if (tmp == n) {
        break;
      }
    }
    cout << sum << endl;
  }
  return 0;
}
