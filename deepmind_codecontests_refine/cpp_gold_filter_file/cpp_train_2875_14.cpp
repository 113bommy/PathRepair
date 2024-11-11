#include <bits/stdc++.h>
using namespace std;
const int INF = 1111111111;
const long long LNF = 11111111111111111;
const int MAXN = 222222;
int a[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  if (k && k < n) {
    cout << 1 << ' ';
  } else {
    cout << 0 << ' ';
  }
  cout << min(2 * k, n - k);
}
