#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int n, a[N], b[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]] = i;
  }
  for (int i = 0; i < n; i++)
    for (int j = min(i + 100, n - 1); j > i; j--) {
      int nxt1 = 2 * a[j] - a[i], nxt2 = 2 * a[i] - a[j];
      if ((nxt1 > 0 && nxt1 <= n && b[nxt1] > j) ||
          (nxt2 > 0 && nxt2 <= n && b[nxt2] < i))
        return cout << "YES", 0;
    }
  cout << "NO";
}
