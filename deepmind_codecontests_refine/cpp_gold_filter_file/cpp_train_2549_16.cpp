#include <bits/stdc++.h>
using namespace std;
inline int nxt() {
  int a;
  scanf("%d", &a);
  return a;
}
inline long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
void solve() {
  string s;
  cin >> s;
  int ans = 0;
  ans += 26;
  ans += 25 * s.length();
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  solve();
  return 0;
}
