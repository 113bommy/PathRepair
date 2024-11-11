#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int MAXM = 100010;
const int MAXP = 666666;
const int MAX = 1e5 + 7;
const int mod = 998244353;
const double eps = 1e-7;
int ca = 1;
int n;
void solve() {
  cin >> n;
  cout << n << endl;
  for (long long i = 2; i <= n; i++)
    cout << (i + 1) * (i + 1) * i - (i - 1) << endl;
}
int main() {
  int t = 1;
  while (t--) solve();
}
