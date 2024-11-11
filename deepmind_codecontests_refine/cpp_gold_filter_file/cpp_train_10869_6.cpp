#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
int n, a[200], m;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  m = 100000;
  for (int i = 0; i < n - 1; i++) {
    int s = abs(a[i] - a[i + 1]);
    m = min(s, m);
  }
  m = min(m, abs(a[0] - a[n - 1]));
  for (int i = 0; i < n - 1; i++) {
    if (abs(a[i] - a[i + 1]) == m) {
      cout << i + 1 << " " << i + 2;
      return 0;
    }
  }
  if (abs(a[0] - a[n - 1]) == m) cout << n << " " << 1;
  return 0;
}
