#include <bits/stdc++.h>
using namespace std;
int n, a[105], b[105], f1, f2;
string st;
int main() {
  cin >> n >> st;
  if (n == 1 && st[0] == st[1]) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < n; ++i) a[i] = st[i] - '0';
  for (int i = n; i < 2 * n; ++i) b[i - n] = st[i] - '0';
  sort(a, a + n);
  sort(b, b + n);
  for (int i = 0; i < n; ++i) {
    if (a[i] >= b[i]) f1 = 1;
    if (a[i] <= b[i]) f2 = 1;
    if (f1 && f2) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
}
