#include <bits/stdc++.h>
using namespace std;
const long long md = 1e9 + 7;
long long a[1000005], n;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q, m, k, h, ans = 0, sum = 0, p, x, y;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    ans = max(ans, x);
  }
  cout << (x > 25 ? x - 25 : 0);
}
