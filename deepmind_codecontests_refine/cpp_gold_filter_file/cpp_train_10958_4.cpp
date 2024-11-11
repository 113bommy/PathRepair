#include <bits/stdc++.h>
using namespace std;
long long mini(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long maxi(long long a, long long b) {
  if (a > b) return a;
  return b;
}
void solve() {
  int temp;
  long long x0, x1, x2;
  long long y0, y1, y2;
  cin >> x0 >> x1 >> x2 >> y0 >> y1 >> y2;
  long long sum = 0;
  long long mine = mini(x1, y0);
  x1 -= mine;
  y0 -= mine;
  mine = mini(x0, y2);
  x0 -= mine;
  y2 -= mine;
  mine = mini(x2, y1);
  x2 -= mine;
  y1 -= mine;
  sum += mine * 2;
  mine = mini(x1, y2);
  sum += -(mine * 2);
  cout << sum;
  cout << "\n";
  ;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
