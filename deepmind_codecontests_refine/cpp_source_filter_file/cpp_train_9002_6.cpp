#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9;
const long long N = 1e5 + 7;
const long long mod = 1e9 + 7;
const long double eps = 1E-7;
long long n;
long long a, b, c, d;
long long cnt;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c >> d;
    cnt += (c - a) * (d - b);
  }
  cout << cnt << endl;
  return 0;
}
