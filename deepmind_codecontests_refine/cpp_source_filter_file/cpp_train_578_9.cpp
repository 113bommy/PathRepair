#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, l, r;
  cin >> n >> l >> r;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  if (r == n) {
    sort(a.begin() + l - 1, a.end());
    sort(b.begin() + l - 1, b.end());
  } else {
    sort(a.begin() + l - 1, a.begin() + r);
    sort(b.begin() + l - 1, b.begin() + r);
  }
  int i = 0;
  while (i < n && a[i] == b[i]) {
    ++i;
  }
  if (i == r) {
    cout << "TRUTH\n";
  } else {
    cout << "LIE\n";
  }
  return 0;
}
