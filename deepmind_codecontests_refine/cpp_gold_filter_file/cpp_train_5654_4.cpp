#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN = 100, MAXT = 50000;
int t[MAXN + 2];
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int k = 0, mx, cum = 1;
  t[k++] = 1;
  if (b == 0 && a != 0) cum += t[k++] = 1;
  for (int i = 0; i < b; i++) cum += t[k++] = cum + 1;
  mx = t[k - 1];
  for (int i = 0; i < a; i++) t[k++] = mx += 1;
  while (k < n) t[k++] = 1;
  if (k > n || mx > MAXT) {
    cout << -1 << '\n';
  } else {
    cout << t[0];
    for (int i = 1; i < n; i++) cout << ' ' << t[i];
    cout << '\n';
  }
}
