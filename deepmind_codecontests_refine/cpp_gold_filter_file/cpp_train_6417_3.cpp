#include <bits/stdc++.h>
using namespace std;
void solve();
signed main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(9);
  solve();
}
const long long INF = 1e9, MAXN = 3e5 + 10, MOD = 998244353;
bool correct(long long num) {
  long long sum = 0;
  while (num != 0) {
    sum += (num % 10);
    num /= 10;
  }
  return sum == 10;
}
void solve() {
  vector<long long> zbs;
  for (long long i = 1; i <= 2e7; ++i) {
    if (correct(i)) {
      zbs.push_back(i);
    }
  }
  long long k;
  cin >> k;
  cout << zbs[k - 1] << "\n";
}
