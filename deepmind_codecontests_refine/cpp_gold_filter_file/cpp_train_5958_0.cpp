#include <bits/stdc++.h>
using namespace std;
const long long N = 200005;
const long long X = 500000;
void flash() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(12);
}
bool alu(long long num) {
  while (num % 2 == 0) num /= 2;
  while (num % 3 == 0) num /= 3;
  if (num == 1)
    return false;
  else
    return true;
}
void solve();
int32_t main() {
  flash();
  long long t;
  t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
void solve() {
  long long n, g, b;
  cin >> n >> g >> b;
  long long needG = (n / 2) + (n % 2 >= 1);
  long long tot = (needG / g) * (g + b);
  long long rem = needG % g;
  if (rem == 0) tot -= b;
  cout << max(tot + rem, n) << "\n";
  return;
}
