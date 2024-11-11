#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN];
bool check(int x, int n) {
  for (int i = 0; i < n; ++i) {
    if (a[i] + b[i] > x) return false;
  }
  return true;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(a, a + n);
    sort(b, b + n);
    reverse(b, b + n);
    if (check(x, n)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
