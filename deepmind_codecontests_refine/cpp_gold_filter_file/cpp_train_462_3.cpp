#include <bits/stdc++.h>
using namespace std;
vector<long long int> prime;
unordered_set<long long int> stprime;
vector<long long int> sqr;
void sieve(long long int n) {
  bool p[n + 1];
  memset(p, true, sizeof(p));
  for (long long int i = 2; i * i <= n; i++) {
    if (p[i]) {
      for (int j = i * i; j <= n; j += i) {
        p[j] = false;
      }
    }
  }
  for (long long int i = 2; i <= n; i++) {
    if (p[i]) {
      prime.push_back(i);
      stprime.insert(i);
    }
  }
}
void solve() {
  long long int r, x, y, x1, y1;
  cin >> r >> x >> y >> x1 >> y1;
  double d = sqrt(pow(y - y1, 2.0) + pow(x - x1, 2.0));
  cout << (int)(ceil)(d / r / 2) << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
