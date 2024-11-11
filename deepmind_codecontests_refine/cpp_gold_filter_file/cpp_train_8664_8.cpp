#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
int n, m, l[N], p[N];
int main() {
  cin >> n >> m;
  int s = 0;
  for (int i = 1; i <= m; i++) {
    cin >> l[i];
    s += l[i];
    s = min(s, n);
    p[i] = i;
    if (p[i] > (n - l[i] + 1)) {
      puts("-1");
      return 0;
    }
  }
  if (s < n) {
    puts("-1");
    return 0;
  }
  for (int i = m; i >= 1; i--) {
    int e = p[i] + l[i] - 1;
    if (e <= n) {
      int nd = n - e;
      p[i] += nd;
      n = p[i] - 1;
    } else {
      break;
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << p[i] << " ";
  }
}
