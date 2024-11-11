#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int main() {
  int n, m, r;
  cin >> n >> m >> r;
  int a[maxn], b[maxn];
  int minn1 = 100000000;
  int maxx2 = -100000000;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    minn1 = min(minn1, a[i]);
  }
  for (int j = 1; j <= n; ++j) {
    cin >> b[j];
    maxx2 = max(maxx2, b[j]);
  }
  int sy, cnt;
  if (minn1 < maxx2) {
    sy = r % minn1;
    cnt = r / minn1;
    cout << sy + cnt * maxx2;
  } else
    cout << r;
  return 0;
}
