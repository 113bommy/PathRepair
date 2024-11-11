#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000007;
int c[MAXN + 10] = {0};
int main() {
  cin.sync_with_stdio(false);
  int n, w, res = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> w;
    c[w]++;
  }
  for (int i = 0; i < MAXN; ++i) {
    if (c[i] != 0) {
      c[i + 1] += c[i] / 2;
      c[i] %= 2;
      res += c[i];
    }
  }
  cout << res;
  return 0;
}
