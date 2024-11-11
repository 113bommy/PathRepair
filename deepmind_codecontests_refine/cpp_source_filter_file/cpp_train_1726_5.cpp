#include <bits/stdc++.h>
using namespace std;
const int N6 = 1e6 + 6;
const int N9 = 1e9 + 7;
const double eps = 1e-8;
const long long N = 250000;
long long n, l, a[55], b[55], sum;
map<long long, long long> cnt;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL);
  cin >> n >> l;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt[a[i]] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; ++i) {
    if (cnt[b[i]] >= 1) ++sum;
  }
  if (sum == n) {
    cout << "YES";
    exit(0);
  }
  for (int j = 1; j <= n * 10; ++j) {
    sum = 0;
    for (int i = 1; i <= n; ++i) {
      ++b[i];
      b[i] %= l;
    }
    for (int i = 1; i <= n; ++i) {
      if (cnt[b[i]] >= 1) ++sum;
    }
    if (sum == n) {
      cout << "YES";
      exit(0);
    }
  }
  cout << "NO";
  return 0;
}
