#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fLL;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int arr[100005];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b + 2 > n || a > (n - 1) / 2 || b > (n - 1) / 2) {
      cout << -1 << endl;
      continue;
    }
    if (abs(a - b) > 1) {
      cout << -1 << endl;
      continue;
    }
    if (a > b) {
      for (int i = 1; i <= n - (2 * a + 2); ++i) {
        cout << i << " ";
      }
      cout << n - (2 * a) << " ";
      int i = n - (2 * a) + 2, j = n;
      for (; i < j; ++i, --j) {
        cout << i << " " << j << " ";
      }
      if (i == j) cout << i << " ";
      cout << n - (2 * a) + 1 << " ";
      cout << endl;
    } else if (a < b) {
      for (int i = n; i >= 2 * b + 2; --i) {
        cout << i << " ";
      }
      cout << 2 * b + 1 << " ";
      int i = 2 * b - 1, j = 1;
      for (; i > j; --i, ++j) {
        cout << j << " " << i << " ";
      }
      if (i == j) cout << i << " ";
      cout << 2 * b << " ";
      cout << endl;
    } else {
      for (int i = 1; i <= n - (2 * a + 2); ++i) {
        cout << i << " ";
      }
      cout << n - (2 * a + 1) << " ";
      int i = n - (2 * a + 1) + 1, j = n - 1;
      for (; i < j; ++i, --j) {
        cout << j << " " << i << " ";
      }
      if (i == j) cout << i << " ";
      cout << n << " ";
      cout << endl;
    }
  }
}
