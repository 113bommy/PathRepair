#include <bits/stdc++.h>
using namespace std;
void solve() {}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n;
  cin >> n;
  int x, y, z, a, b, c;
  x = y = z = 0;
  while (n--) {
    cin >> a >> b >> c;
    x += a;
    y += b;
    z += c;
  }
  if (z + y + x)
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
