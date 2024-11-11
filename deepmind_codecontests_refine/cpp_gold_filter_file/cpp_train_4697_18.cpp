#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a, b, c;
  cin >> a >> b >> c;
  long long ans = 0;
  while (a >= b + c) {
    b++;
    ans++;
  }
  while (a <= abs(b - c)) {
    a++;
    ans++;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(0);
  solve();
}
