#include <bits/stdc++.h>
using namespace std;
int a[500001], c[500001], n;
long long s, r;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (s % 3) {
    cout << 0 << "\n";
    return 0;
  }
  s /= 3;
  for (long long i = n - 1, t = 0; i >= 0; i--) {
    c[i] = c[i + 1] + ((t += a[i]) == s);
  }
  for (long long i = 0, t = 0; i < n - 2; i++) {
    if ((t += a[i]) == s) {
      r += c[i + 1] - (!s);
    }
  }
  cout << r << "\n";
  return 0;
}
