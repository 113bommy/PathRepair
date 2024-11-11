#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
const int infi = 1e9 + 7;
const long long infl = 1e18;
const long double eps = 1e-7;
const long double eps1 = 1e-10;
const int mod = (1e9 + 7);
const long long mod1 = 1e9 + 7;
const long long mod2 = 1e9 + 7;
const long long p1 = 31;
const long long p2 = 37;
const long long p3 = 29;
const int ver1 = (62 * 62);
vector<int> ans[1000500];
int used[1000500];
int main() {
  int n, k;
  cin >> n >> k;
  if (k * 3 > n) {
    cout << -1;
    return 0;
  }
  int q = 1;
  ans[0].reserve(n);
  for (int i = 0; i < k; ++i) {
    used[q++] = i + 1;
    used[q++] = i + 1;
  }
  for (int i = 0; i < k; ++i) {
    used[q++] = i + 1;
  }
  while (q < n) {
    used[q++] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", used[i]);
  }
  return 0;
}
