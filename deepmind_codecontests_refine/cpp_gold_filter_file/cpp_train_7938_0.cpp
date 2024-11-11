#include <bits/stdc++.h>
using namespace std;
void fun() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  cout << x << " " << y << '\n';
  for (int i = 1; i < x; i++) cout << i << " " << y << '\n';
  for (int i = x + 1; i <= n; i++) cout << i << " " << y << '\n';
  int r1 = y - 1, r2 = n;
  while (r1 > 0) {
    r2 = n;
    while (r2 > 0) {
      cout << r2 << " " << r1 << '\n';
      r2--;
    }
    r1--;
    if (r1) {
      r2 = 1;
      while (r2 <= n) {
        cout << r2 << " " << r1 << '\n';
        r2++;
      }
      r1--;
    }
  }
  r1 = y + 1;
  while (r1 <= m) {
    if (r2 == n + 1) {
      r2 = n;
      while (r2 > 0) {
        cout << r2 << " " << r1 << '\n';
        r2--;
      }
    } else if (r2 == 0) {
      r2 = 1;
      while (r2 <= n) {
        cout << r2 << " " << r1 << '\n';
        r2++;
      }
    }
    r1++;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  srand(time(0));
  ;
  int t = 1;
  while (t--) {
    fun();
  }
}
