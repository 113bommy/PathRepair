#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a, r, l;
  int n;
  cin >> n;
  a.resize(n);
  r.resize(n);
  l.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  r[0] = a[0];
  for (int i = 1; i < n; i++) {
    r[i] = a[i] + r[i - 1];
  }
  l[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    l[i] = l[i + 1] + a[i];
  }
  int c = 0;
  for (int i = 0; i < n - 1; i++) {
    if (r[i] == l[i + 1]) {
      c++;
    }
  }
  cout << c << endl;
  return 0;
}
