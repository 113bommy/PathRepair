#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const long long LLINF = 1000000000000000007LL;
const double EPS = 1e-9;
const int sz = 100500;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cout << (x / 7) + bool(x % 7);
  }
}
