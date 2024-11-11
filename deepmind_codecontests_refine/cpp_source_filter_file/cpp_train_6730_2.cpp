#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
long long a[N];
int main() {
  long long n;
  cin >> n;
  long long maxx = -1e9, minn = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    maxx = max(a[i], maxx);
    minn = min(a[i], minn);
  }
  if (maxx - minn <= 1) {
    cout << n << endl;
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;
    return 0;
  }
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == maxx) x++;
    if (a[i] == maxx - 1) y++;
    if (a[i] == minn) z++;
  }
  int ans1 = y + ((x == z) ? 0 : abs(z - x));
  int ans2 = x + z + y % 2;
  if (ans1 <= ans2) {
    cout << ans1 << endl;
    if (x >= z) {
      for (int i = 0; i < x - z; i++) cout << maxx << ' ';
      for (int i = 0; i < y + min(z, x) * 2; i++) cout << maxx - 1 << ' ';
    } else {
      for (int i = 0; i < z - x; i++) cout << minn << ' ';
      for (int i = 0; i < y + min(z, x) * 2; i++) cout << maxx - 1 << ' ';
    }
  } else {
    cout << ans2 << endl;
    for (int i = 0; i < x + y / 2; i++) cout << minn << ' ';
    for (int i = 0; i < y % 2; i++) cout << maxx - 1 << ' ';
    for (int i = 0; i < z + y / 2; i++) cout << maxx << ' ';
  }
  cout << endl;
  return 0;
}
