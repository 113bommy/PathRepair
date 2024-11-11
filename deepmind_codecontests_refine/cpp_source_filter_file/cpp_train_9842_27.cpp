#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double PI = acos(-1);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long double d, h, v, e;
  cin >> d >> h >> v >> e;
  long double r = d / 2;
  long double ml = h * PI * r * r;
  long double inc = e * PI * r * r;
  if (inc >= v) {
    cout << "NO\n";
    return 0;
  }
  long double diff = e - inc;
  cout << "YES\n";
  cout << fixed << setprecision(12) << ml / diff << '\n';
}
