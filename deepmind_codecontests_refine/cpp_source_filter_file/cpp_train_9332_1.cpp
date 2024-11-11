#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<long long int> a(n);
  vector<long long int> b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < b.size() - 1; i++) {
    if (b[i] == b[i + 1]) {
      b.erase(b.begin() + i, b.begin() + i + 1);
      i--;
    }
  }
  long long int l = 1e18;
  for (int k = 0; k < n; k++) {
    long long int x = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < b.size(); j++) {
        if (i != k) {
          x = max(x, a[i] * b[j]);
        }
      }
    }
    l = min(l, x);
  }
  cout << l << endl;
  return 0;
}
