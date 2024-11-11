#include <bits/stdc++.h>
using namespace std;
long long int hcf(long long int a, long long int b) {
  if (b == 0) return a;
  return hcf(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / hcf(a, b);
}
bool isprime(long long int n) {
  if (n == 1) return false;
  for (long long int i = 2; i * i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}
void solve() {
  long long int n, x, y;
  cin >> n >> x >> y;
  vector<long long int> ans(4);
  for (long long int i = 0; i <= n - 1; i++) {
    long long int xx, yy;
    cin >> xx >> yy;
    xx -= x;
    yy -= y;
    if (xx > 0) ans[0]++;
    if (xx < 0) ans[2]++;
    if (yy > 0) ans[1]++;
    if (yy < 0) ans[3]++;
  }
  vector<long long int> b = ans;
  sort(b.begin(), b.end());
  cout << b[3] << "\n";
  for (long long int i = 0; i <= 3; i++) {
    if (ans[i] == b[0]) {
      if (i == 0) {
        cout << x + 1 << " " << y << "\n";
      } else if (i == 1) {
        cout << x << " " << y + 1 << "\n";
      } else if (i == 2) {
        cout << x - 1 << " " << y << "\n";
      } else if (i == 3) {
        cout << x << " " << y - 1 << "\n";
      }
      return;
    }
  }
}
void onlinejudge() {}
int main() {
  onlinejudge();
  long long int ttt;
  ttt = 1;
  cout << fixed << setprecision(16);
  while (ttt--) solve();
  return 0;
}
