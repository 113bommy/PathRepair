#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long big = inf * 1LL * inf;
const int maxn = 1e6;
const int mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  long long sum = accumulate(a, a + n, 0);
  if (sum % 2) {
    cout << "NO";
  } else {
    for (int i = 0; i < n; ++i) {
      if (sum - a[i] < a[i]) {
        cout << "NO";
        return 0;
      }
    }
    cout << "YES";
  }
}
