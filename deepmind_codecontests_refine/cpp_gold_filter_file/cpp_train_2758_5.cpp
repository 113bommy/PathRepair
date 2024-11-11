#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100009];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l[100009], r[100009];
  l[0] = 1;
  for (int i = 1; i < n; i++) {
    l[i] = min(l[i - 1] + 1, a[i]);
  }
  r[n - 1] = 1;
  int ma = 1;
  for (int i = n - 2; i >= 0; i--) {
    r[i] = min(r[i + 1] + 1, min(a[i], l[i]));
    ma = max(ma, r[i]);
  }
  cout << ma;
}
