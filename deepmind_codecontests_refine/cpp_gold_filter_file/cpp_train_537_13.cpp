#include <bits/stdc++.h>
using namespace std;
void file() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long N = 2e5 + 7;
const long long MOD = 1e9 + 7;
long long n, m, nn, a[N * 10], d, b[N * 10];
int main() {
  file();
  cin >> nn;
  for (int ii = 0; ii < nn; ++ii) {
    cin >> n >> m >> d;
    long long k = 0;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < d; ++i) {
      if (!b[a[i]]) ++k;
      ++b[a[i]];
    }
    long long mn = 1e9;
    for (int i = d - 1; i < n; ++i) {
      mn = min(mn, k);
      b[a[i - d + 1]]--;
      if (!b[a[i - d + 1]]) --k;
      if (!b[a[i + 1]]) ++k;
      b[a[i + 1]]++;
    }
    for (int i = 0; i <= n; ++i) {
      b[a[i]] = 0;
    }
    cout << mn << '\n';
  }
}
