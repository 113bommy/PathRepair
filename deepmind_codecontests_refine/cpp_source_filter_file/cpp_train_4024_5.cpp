#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5;
long long n, d, nd;
bool a[N];
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; ++i) cin >> a[i];
  while (a[d] == a[0]) d++;
  for (long long i = 0; i < n; ++i) {
    long long j = i;
    while (j < n && a[j] == a[i]) j++;
    if (j - i != d) {
      cout << "NO";
      return 0;
    }
    i = j - 1;
  }
  cout << "YES";
}
