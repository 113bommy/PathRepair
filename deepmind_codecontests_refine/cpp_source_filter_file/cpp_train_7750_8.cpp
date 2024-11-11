#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, c, d, n, s;
  cin >> n >> s;
  int cnt = 0;
  int mx = -1;
  for (i = 0; i < n; i++) {
    cin >> d >> c;
    int tot = s * 100;
    int have = d * 100 + c;
    if (have > tot) {
      cnt++;
      continue;
    }
    int rest = tot % have;
    rest = rest % 100;
    mx = max(mx, rest);
  }
  cout << mx << endl;
  return 0;
}
