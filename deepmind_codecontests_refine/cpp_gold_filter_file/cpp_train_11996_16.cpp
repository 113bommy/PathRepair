#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n, m, a[N], k;
int main() {
  cin >> n >> m;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = i;
    cnt += (i - 1) / 2;
    if (cnt >= m) {
      a[i] += (cnt - m) << 1;
      for (int j = n, k = 1e9; j > i; j--, k -= i + 1) {
        a[j] = k;
      }
      for (int j = 1; j <= n; j++) {
        cout << a[j] << " ";
      }
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
