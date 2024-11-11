#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long a[N], b[N], d, n, x, pos[N], q[N], s;
long long getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  for (int i = 0; i < n; i = i + 1) {
    a[i] = i + 1;
  }
  for (int i = 0; i < n; i = i + 1) {
    swap(a[i], a[getNextX() % (i + 1)]);
  }
  for (int i = 0; i < n; i++) pos[a[i]] = i;
  for (int i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (int i = 0; i < n; i = i + 1) {
    swap(b[i], b[getNextX() % (i + 1)]);
  }
  for (int i = 0; i < n; i++)
    if (b[i]) q[++q[0]] = i;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> d >> x;
  initAB();
  s = 30;
  for (int i = 0; i < n; i++) {
    int j;
    for (j = n; j >= n - s; j--) {
      if (j > 0 && i >= pos[j] && b[i - pos[j]]) {
        cout << j << "\n";
        break;
      }
    }
    if (j < n - s) {
      long long c = 0;
      for (int j = 1; j <= q[0] && q[0] <= i; j++) {
        c = max(c, a[i - q[j]]);
      }
      cout << c << "\n";
    }
  }
  return 0;
}
