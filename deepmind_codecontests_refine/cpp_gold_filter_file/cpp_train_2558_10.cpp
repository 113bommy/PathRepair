#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010;
struct rec {
  int x1;
  int y1;
  int x2;
  int y2;
} a[maxn];
int color(rec a) { return 2 * (a.x1 & 1) + (a.y1 & 1) + 1; }
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << color(a[i]) << endl;
  return 0;
}
