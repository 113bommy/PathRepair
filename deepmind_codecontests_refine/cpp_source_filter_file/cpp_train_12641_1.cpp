#include <bits/stdc++.h>
using namespace std;
long long maxi = LLONG_MIN;
long long mini = LLONG_MAX;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long t, i, j, k, n, temp, flag, ans, m;
int main() {
  long long n, m, x, y, z, p, a, b, ans1, ans2, l1, l2;
  cin >> n >> m >> x >> y >> z >> p;
  for (int i = 1; i <= p; i++) {
    cin >> a >> b;
    ans1 = a;
    ans2 = b;
    x = x % 4;
    y = y % 4;
    z = z % 4;
    l1 = n;
    l2 = m;
    if (x == 1) {
      long long t = ans2;
      ans2 = l1 - ans1 + 1;
      ans1 = t;
      l1 = m;
      l2 = n;
    } else if (x == 2) {
      ans2 = l2 - ans2 + 1;
      ans1 = l1 - ans1 + 1;
    } else if (x == 3) {
      long long t = ans2;
      ans2 = ans1;
      ans1 = l2 - t + 1;
      l1 = m;
      l2 = n;
    }
    if (y == 1) {
      ans2 = l2 - ans2 + 1;
    }
    if (z == 1) {
      long long t = ans2;
      ans2 = ans1;
      ans1 = l2 - t + 1;
      l1 = m;
      l2 = n;
    } else if (z == 2) {
      ans2 = l2 - ans2 + 1;
      ans1 = l1 - ans1 + 1;
    } else if (z == 3) {
      long long t = ans2;
      ans2 = l1 - ans1 + 1;
      ans1 = t;
      l1 = m;
      l2 = n;
    }
    cout << ans1 << " " << ans2 << "\n";
  }
  return 0;
}
