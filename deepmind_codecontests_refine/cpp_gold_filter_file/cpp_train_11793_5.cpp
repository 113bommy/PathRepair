#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  double n, R, r;
  cin >> n >> R >> r;
  if (r > R) {
    cout << "NO\n";
    exit(0);
  } else if (2 * r > R) {
    cout << ((n == 1) ? "YES\n" : "NO\n");
    exit(0);
  }
  double sinThetaHalf = r / (R - r);
  double theta = 2 * abs(asin(sinThetaHalf));
  double pieHalf = asin(1);
  double doublePie = 2 * acos(-1);
  if (n * theta - doublePie <= 1e-7)
    cout << "YES\n";
  else
    cout << "NO\n";
}
