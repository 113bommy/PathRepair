#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m;
int a[N], b[N];
int main() {
  int res = 0;
  int w, h, k;
  cin >> w >> h >> k;
  for (int i = 1; i <= k; i++) {
    res += w * h - (w - 2) * (h - 2);
    w -= 4, h -= 4;
  }
  cout << res;
}
