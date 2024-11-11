#include <bits/stdc++.h>
using namespace std;
int hb[105], hg[105];
int main() {
  int n, m, b, g;
  cin >> n >> m;
  cin >> b;
  for (int i = 1; i <= b; i++) {
    int cnt;
    cin >> cnt;
    hb[cnt] = 1;
  }
  cin >> g;
  for (int i = 1; i <= g; i++) {
    int cnt;
    cin >> cnt;
    hg[i] = cnt;
  }
  for (int i = 0; i <= 1000000; i++) {
    if (hb[i % n] == 1 || hg[i % m] == 1) {
      hb[i % n] = 1;
      hg[i % m] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (hb[i] == 0) {
      cout << "No\n";
      return 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (hg[i] == 0) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}
