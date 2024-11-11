#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
long long a[27];
int n, m;
int main() {
  int x, y;
  cin >> x >> y >> n;
  if (n + 2 > x + y) {
    cout << "-1";
    return 0;
  }
  n += 2;
  long long ans1 = 0, ans2 = 0;
  if (x < n) {
    ans1 = y / (n - x);
  } else
    ans1 = y * (x / (n - 1));
  if (y < n) {
    ans2 = x / (n - y);
  } else
    ans2 = x * (y / (n - 1));
  cout << max(ans1, ans2) << endl;
}
