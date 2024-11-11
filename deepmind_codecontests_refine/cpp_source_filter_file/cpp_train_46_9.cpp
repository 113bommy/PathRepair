#include <bits/stdc++.h>
using namespace std;
int main() {
  int n{0};
  unsigned long f{0}, s{0};
  cin >> n;
  vector<unsigned long> a(n), b(n - 1), c(n - 2);
  for (unsigned i{0}; i < a.size(); i++) {
    cin >> a[i];
  }
  for (unsigned i{0}; i < b.size(); i++) {
    cin >> b[i];
  }
  for (unsigned i{0}; i < c.size(); i++) {
    cin >> c[i];
  }
  sort(c.begin(), c.end());
  sort(b.begin(), b.end());
  sort(a.begin(), a.end());
  for (unsigned i{0}; i < b.size(); i++) {
    if (a[i] != b[i]) {
      f = a[i];
      break;
    }
  }
  if (!f) {
    f = a[n - 1];
  }
  for (unsigned i{0}; i < c.size(); i++) {
    if (b[i] != c[i]) {
      s = a[i];
      break;
    }
  }
  if (!s) {
    s = b[n - 2];
  }
  cout << f << '\n' << s << endl;
  return 0;
}
