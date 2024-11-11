#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, t;
  int i;
  while (scanf("%d%d%d", &n, &k, &t) != EOF) {
    float m;
    m = t / 100.0 * n;
    float num;
    num = (m - int(m)) * k;
    for (i = 0; i < (int)m; i++) cout << k << ' ';
    if (num < 1) {
      for (; i < n; i++) cout << 0 << ' ';
    } else {
      cout << num << ' ';
      i++;
      for (; i < n; i++) cout << 0 << ' ';
    }
    cout << endl;
  }
  return 0;
}
