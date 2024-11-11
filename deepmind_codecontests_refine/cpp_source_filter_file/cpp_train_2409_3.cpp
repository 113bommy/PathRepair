#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100000];
  int m = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] > m) m = a[i];
  }
  int g = 0, gg = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == m) ++g;
    if (a[i] != m) {
      gg = max(g, gg);
      g = 0;
    }
  }
  cout << gg;
  return 0;
}
