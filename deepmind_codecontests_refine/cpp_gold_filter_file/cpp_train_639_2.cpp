#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;
const int N = 2e5;
const int oo = 1e9;
const double pi = acos(-1);
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> v(m);
  for (int i = 0; i < m; ++i) scanf("%lld", &v[i]);
  int shift = 0, ans = 0;
  for (int i = 0; i < m; ++i) {
    long long page = (v[i] - 1 - shift) / k;
    bool in = false;
    int tmp = shift;
    while (i < m && (v[i] - 1 - shift) / k == page) {
      ++i;
      ++tmp;
      in = true;
    }
    if (in) {
      --i;
      ++ans;
      shift = tmp;
    }
  }
  cout << ans << endl;
  return 0;
}
