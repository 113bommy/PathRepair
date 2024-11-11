#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long l, r, a;
  cin >> l >> r >> a;
  long long mini, maxi;
  mini = min(l, r);
  maxi = max(l, r);
  long long d = maxi - mini;
  if (a <= d) {
    cout << (2 * (mini + a)) << "\n";
  } else {
    long long d1 = a - d;
    cout << 2 * (maxi + (d1 / 2)) << "\n";
  }
}
