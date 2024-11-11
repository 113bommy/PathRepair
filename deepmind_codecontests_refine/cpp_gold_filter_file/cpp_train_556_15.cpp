#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
const long long MOD = 1e9 + 7;
void solve() {
  long long x, y, sum;
  long long a[3][3];
  for (long long i = 0; i < 3; i++) {
    long long temp = 0;
    for (long long j = 0; j < 3; j++) {
      cin >> a[i][j];
      temp += a[i][j];
    }
    if (i == 0) x = temp;
    if (i == 2)
      y = temp;
    else
      sum = temp;
  }
  for (long long i = 1; i <= 1e5; i++) {
    long long check = sum + i;
    long long temp1 = check - x;
    long long temp2 = check - y;
    if (temp1 > 0 && temp2 > 0 && (temp1 + temp2 + i == check)) {
      a[1][1] = i;
      a[0][0] = temp1;
      a[2][2] = temp2;
      break;
    }
  }
  for (long long i = 0; i < 3; i++) {
    for (long long j = 0; j < 3; j++) {
      cout << a[i][j] << " ";
    }
    cout << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
