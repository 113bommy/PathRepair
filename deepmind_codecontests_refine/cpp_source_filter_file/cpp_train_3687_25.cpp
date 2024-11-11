#include <bits/stdc++.h>
using namespace std;
string tos(int a) {
  ostringstream os("");
  os << a;
  return os.str();
}
int k, n, a[100000];
int main() {
  while (cin >> n >> k) {
    for (int i = (int)0; i < (int)n; ++i) cin >> a[i];
    int min = (1 << 30), ans = 0;
    for (int i = k - 1; i >= 0; --i) {
      int acum = 0;
      for (int j = i; j < n; j += k) {
        acum += a[j];
      }
      if (acum < min) min = acum, ans = i;
    }
    cout << ans + 1 << endl;
  }
  return 0;
}
