#include <bits/stdc++.h>
using namespace std;
long long r, b, k;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
void readIN() {
  cin >> r >> b >> k;
  if (b > r) swap(r, b);
}
void solve() {
  long long c = gcd(r, b);
  r /= c;
  b /= c;
  if (ceil((double)(r - 1) / (double)b) >= (double)k)
    cout << "rEbEl" << endl;
  else
    cout << "obEY" << endl;
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  int T;
  cin >> T;
  while (T--) {
    readIN();
    solve();
  }
  return 0;
}
