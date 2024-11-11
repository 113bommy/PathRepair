#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
void solve() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  double a, ans = 0;
  cin >> a;
  while (a >= 2) {
    ans += ((a - 1) / (a));
    a -= 1;
  }
  printf("%.9lf\n", ans + 1);
  return 0;
}
