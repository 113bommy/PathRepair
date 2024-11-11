#include <bits/stdc++.h>
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
using namespace std;
int begtime = clock();
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngb(chrono::steady_clock::now().time_since_epoch().count());
vector<long long int> fact(long long int n) {
  vector<long long int> res;
  for (long long d = 1, i = 2; i * i <= n && res.size() <= 3; i += d, d = 2) {
    while (n % i == 0) {
      res.push_back(i);
      n /= i;
    }
  }
  if (n > 1) res.push_back(n);
  return res;
}
void solve() {
  long long int n;
  cin >> n;
  vector<long long int> res = fact(n);
  if (((long long int)(res).size()) <= 1) {
    cout << 1 << "\n" << 0 << "\n";
  } else if (((long long int)(res).size()) == 2) {
    cout << 2 << "\n";
  } else {
    cout << 1 << "\n" << res[0] + res[1] << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
