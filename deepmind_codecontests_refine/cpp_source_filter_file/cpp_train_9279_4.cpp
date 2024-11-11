#include <bits/stdc++.h>
using namespace std;
struct edge {
  long long a, b, cost;
  edge(long long x, long long y, long long z) : a(x), b(y), cost(z){};
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, x, y, ans = 0, f = 0;
  cin >> n >> x >> y;
  vector<long long> v(n);
  for (long long i = 0; i < (long long)(n - 1); i++) v[i] = 1;
  v[n - 1] = y - (n - (long long)1);
  if (v[n - 1] < 0) f = 1;
  for (long long i = (long long)(0); i <= (long long)(n - 1); i++) {
    ans += (v[i] * v[i]);
    if (ans >= x) break;
  }
  if (ans < x) f = 1;
  if (!f) {
    for (long long i = (long long)(0); i <= (long long)(n - 1); i++)
      cout << v[i] << endl;
  } else
    cout << "-1" << endl;
  return 0;
}
