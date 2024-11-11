#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18 + 123;
const long double EPS = 1e-9;
const int MX = 1e9 + 1;
const int inf = 1e9 + 123;
const int MOD = 1e9 + 7;
const int N = 5e5 + 123;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  if (n == 3) {
    cout << 1 << " " << 1 << " " << 1;
    return 0;
  }
  if ((n - 2) % 3 == 0) {
    cout << 1 << " " << 1 << " " << n - 2;
  } else {
    cout << 1 << " " << 2 << " " << n - 3;
  }
  return 0;
}
