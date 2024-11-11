#include <bits/stdc++.h>
using namespace std;
int dx[]{1, -1, 0, 0, 1, 1, -1, -1};
int dy[]{0, 0, 1, -1, 1, -1, 1, -1};
void K_K() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  K_K();
  int n, x;
  cin >> n >> x;
  if (n == 1) return cout << "YES\n" << x, 0;
  if (n == 2 && !x) return cout << "NO", 0;
  if (n == 2) return cout << "YES\n0 " << x, 0;
  cout << "YES\n";
  for (int i = 1; i <= n - 3; i++) {
    cout << i << ' ';
    x ^= i;
  }
  int a = 17, b = 18;
  cout << (x ^ (1 << a)) << ' ' << (1 << b) << ' ' << ((1 << a) ^ (1 << b));
}
