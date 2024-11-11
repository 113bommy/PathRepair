#include <bits/stdc++.h>
using namespace std;
const int N = (int)3e5 + 1;
const int inf = (int)1e9 + 7;
const int M = 101;
char a[2][2], b[2][2];
int main() {
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  for (int i = 0; i < min(n / 2, k); ++i) {
    ans += 2 * (n - 2 - 2 * i) + 1;
  }
  cout << ans;
  return 0;
}
