#include <bits/stdc++.h>
using namespace std;
;
const double eps = 1e-8;
const int mod = 1000000007;
const int maxn = 1e6 + 7;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f;
int x;
int p[maxn];
void init() {
  for (int i = 2; i <= maxn; i++) {
    p[i] = 1;
  }
  for (int i = 2; i * i < maxn; i++) {
    if (p[i] == 1) {
      for (int j = i * 2; j < maxn; j += i) {
        p[j] = i;
      }
    }
  }
}
int main() {
  init();
  cin >> x;
  int ans = inf;
  for (int i = x - p[x] + 1; i <= x; i++) {
    ans = min(ans, i - p[i] + 1);
  }
  cout << ans << endl;
  return 0;
}
