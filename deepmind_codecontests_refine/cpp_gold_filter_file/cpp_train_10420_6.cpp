#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x;
  cin >> n >> x;
  vector<int> a(n), b(1e5 + 1, 0), c(1e5 + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[a[i]]++;
    c[a[i] & x]++;
  }
  for (int i = 0; i < 1e5 + 1; i++) {
    if (b[i] > 1) {
      cout << 0;
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    b[a[i]]--;
    if (b[a[i] & x]) {
      cout << 1;
      return 0;
    }
    b[a[i]]++;
  }
  for (int i = 0; i < 1e5 + 1; i++) {
    if (c[i] > 1) {
      cout << 2;
      return 0;
    }
  }
  cout << -1;
}
