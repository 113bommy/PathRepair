#include <bits/stdc++.h>
using namespace std;
int n, m, k, a[110][2];
bool is(int i) {
  int x = min(m - a[i][1] + 1, a[i][1]);
  int y = min(n - a[i][0] + 1, a[i][0]);
  if (x < 6 || y < 6) return true;
  return false;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) cin >> a[i][0] >> a[i][1];
  for (int i = 0; i < k; i++) {
    if (is(i)) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
