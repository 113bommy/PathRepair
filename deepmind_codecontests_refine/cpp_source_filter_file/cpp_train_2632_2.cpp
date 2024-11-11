#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, k;
vector<pair<int, int> > v;
long long int mx = 0, mn = 2e18;
long long int mult(long long int x, long long int y, long long int z) {
  return (x + 1) * (y + 2) * (z + 2);
}
void calc(long long int x, long long int y) {
  mx = max(mx, max(mult(x, y, 1), max(mult(y, x, 1), mult(1, x, y))));
  mn = min(mn, min(mult(x, y, 1), min(mult(y, x, 1), mult(1, x, y))));
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) {
      mx = max(mx, max(mult(i, y, x / i),
                       max(mult(y, x, x / i), mult(x / i, x, y))));
      mn = min(mn, min(mult(x, y, x / i),
                       min(mult(y, x, x / i), mult(x / i, x, y))));
    }
  for (int i = 2; i * i <= y; i++)
    if (y % i == 0) {
      mx = max(mx, max(mult(i, x, y / i),
                       max(mult(x, i, y / i), mult(y / i, x, i))));
      mn = min(mn, min(mult(i, x, y / i),
                       min(mult(x, i, y / i), mult(y / i, x, i))));
    }
}
int main() {
  cin >> n;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) v.push_back(make_pair(i, n / i));
  }
  for (int i = 0; i < v.size(); i++) calc(v[i].first, v[i].second);
  cout << mn - n << " " << mx - n << endl;
  return 0;
}
