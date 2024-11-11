#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cout.tie(0);
  int n, m, k;
  int c = 0, b = 0;
  cin >> n >> m >> k;
  int a[1000];
  for (int i = 0; i < 1000; ++i) a[i] = 1000500;
  for (int i = 0; i < n; ++i) {
    cin >> c >> b;
    if (b < a[c]) a[c] = b;
  }
  int s = 0;
  for (int i = 0; i < 1000; ++i) {
    if (a[i] != 1000500) s += a[i];
  }
  cout << min(s, k);
  return 0;
}
