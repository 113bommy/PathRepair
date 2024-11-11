#include <bits/stdc++.h>
using namespace std;
long long int mul(long long int a, long long int b) {
  return ((a % int(1e9 + 7)) * (b % int(1e9 + 7))) % int(1e9 + 7);
}
long long int add(long long int a, long long int b) {
  return ((a % int(1e9 + 7)) + (b % int(1e9 + 7))) % int(1e9 + 7);
}
long long int sub(long long int a, long long int b) {
  long long int ans = ((a % int(1e9 + 7)) - (b % int(1e9 + 7))) % int(1e9 + 7);
  ans %= int(1e9 + 7);
  ans = (ans + int(1e9 + 7)) % int(1e9 + 7);
  return ans;
}
long long int mpow(long long int a, long long int b) {
  long long int ans = 1;
  long long int po = a;
  while (b != 0) {
    if (b % 2) {
      ans = ((ans % int(1e9 + 7)) * (po % int(1e9 + 7))) % int(1e9 + 7);
    }
    po = ((po % int(1e9 + 7)) * (po % int(1e9 + 7))) % int(1e9 + 7);
    b /= 2;
  }
  return ans;
}
void solve() {
  long long int h, w;
  cin >> h >> w;
  long long int ans = 0, ffh, ffw;
  for (int i = 0; i < 2; i++) {
    if (!i) swap(w, h);
    if (!i) swap(ffw, ffh);
    long long int fh = 1LL << (long long int)floor(log2(h) + 1e-6);
    while (w < fh / 1.25) {
      fh /= 2;
    }
    long long int fw = min(w, (long long int)(fh / .8 + 1e-6));
    if (ans < fh * fw) {
      ans = fh * fw;
      ffh = fh;
      ffw = fw;
    } else if (ans == fh * fw) {
      if (i == 1 and fh > ffh) {
        ffh = fh;
        ffw = fw;
      } else if (i == 0 and fw > ffw) {
        ffh = fh;
        ffw = fw;
      }
    }
    if (!i) {
      swap(w, h);
      swap(ffw, ffh);
    }
  }
  cout << ffh << ' ' << ffw << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t;
  solve();
}
