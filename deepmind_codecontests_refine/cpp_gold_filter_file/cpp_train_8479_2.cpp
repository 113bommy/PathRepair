#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int n, k, a[1000 * 1000], w[1000 * 1000], was[1000 * 1000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n - k; i++) cout << i << " ";
  int c = 1;
  int p1 = n - k + 1;
  int p2 = n;
  for (int i = n - k + 1; i <= n; i++) {
    if (c & 1) {
      cout << p2 << " ";
      p2--;
    } else {
      cout << p1 << " ";
      p1++;
    }
    c++;
  }
  return 0;
}
