#include <bits/stdc++.h>
using namespace std;
using ii = pair<long long, long long>;
void solve() {
  long long n, s;
  cin >> n >> s;
  long long a[n + 1];
  a[0] = 0;
  int flag = 0;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long h, m;
    cin >> h >> m;
    a[i] = 60 * h + m;
  }
  if (a[1] - a[0] - 1 >= s) {
    ans = 0;
    flag = 1;
  } else {
    for (long long i = 0; i < n; i++) {
      if (abs(a[i + 1] - a[i] - 2) >= 2 * s) {
        flag = 1;
        ans = a[i] + s + 1;
        break;
      }
    }
  }
  if (flag == 1) {
    long long h = floor(ans / (double)60);
    long long m = ans % 60;
    cout << h << " " << m << endl;
  } else {
    ans = a[n] + s + 1;
    long long h = floor(ans / (double)60);
    long long m = ans % 60;
    cout << h << " " << m << endl;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
