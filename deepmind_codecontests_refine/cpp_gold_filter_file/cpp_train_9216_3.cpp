#include <bits/stdc++.h>
using namespace std;
void func() {
  long long n, a, b, c, d, x, y, z, w, cnt = 0;
  cin >> n >> a >> b >> c >> d;
  for (long long i = 1; i < n + 1; i++) {
    x = i;
    y = x + b - c;
    z = x + a - d;
    w = x + a + b - c - d;
    if ((y >= 1 && y <= n) && (z >= 1 && z <= n) && (w >= 1 && w <= n)) cnt++;
  }
  cnt *= n;
  cout << cnt << endl;
}
int main() {
  {
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
  long long q = 1;
  while (q) {
    func();
    q--;
  }
  return 0;
}
