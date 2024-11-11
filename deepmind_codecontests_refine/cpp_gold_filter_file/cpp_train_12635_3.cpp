#include <bits/stdc++.h>
int main() {
  using namespace std;
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k, x;
  cin >> n >> k >> x;
  int s = 0, a = abs(x), i = 0, nn = 0;
  if (k <= n) {
    while (x < 0 && i < k) {
      s += -x;
      a = min(a, -x);
      i++;
      if (i == n) break;
      cin >> x;
    }
    nn = i;
    while (i < n) {
      s += x;
      a = min(a, abs(x));
      if (x < 0) nn++;
      i++;
      if (i == n) break;
      cin >> x;
    }
    if (nn < k && ((k - nn) & 1)) s -= 2 * a;
  } else {
    while (i < n) {
      s += abs(x);
      a = min(a, abs(x));
      if (x < 0) nn++;
      i++;
      if (i == n) break;
      cin >> x;
    }
    if ((k - nn) & 1) s -= 2 * a;
  }
  cout << s << '\n';
}
