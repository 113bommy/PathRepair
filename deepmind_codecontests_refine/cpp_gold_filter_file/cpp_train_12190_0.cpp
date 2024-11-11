#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll prog(ll n) { return n * (n + 1) / 2; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  ll sum = 0;
  for (int i = 0; i < m; i++) {
    int x, d;
    cin >> x >> d;
    if (d < 0) {
      sum += n * x + 1LL * (prog(n / 2) + prog((n + 1) / 2 - 1)) * d;
    } else {
      sum += n * x + 1LL * prog(n - 1) * d;
    }
  }
  cout << fixed << setprecision(10) << double(sum) / double(n) << endl;
}
