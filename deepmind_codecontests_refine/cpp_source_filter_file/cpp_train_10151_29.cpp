#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int maxm = 1e9 + 7;
const int mod = 1e9 + 7;
long long t, w, b;
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t >> w >> b;
  long long fz, fm = t;
  if (w == b) {
    cout << 1 << "/" << 1;
    return 0;
  }
  if (w > b) swap(b, w);
  if (w == 1)
    fz = t / b;
  else {
    long long g = gcd(w, b);
    long long W = w / g;
    long long B = b / g;
    if ((t / W) < B)
      fz = min(t, w - 1);
    else {
      long long lcm = W * B;
      long long num = t / lcm;
      long long r = t % lcm;
      fz = num * w + min(r, w - 1);
    }
  }
  long long g = gcd(fz, fm);
  fz /= g, fm /= g;
  cout << fz << "/" << fm;
}
