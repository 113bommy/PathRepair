#include <bits/stdc++.h>
using namespace std;
long long n;
int ax[10] = {1, -1, -2, -1, 1, 2};
int ay[10] = {2, 2, 0, -2, -2, 0};
string init[8] = {"0 0", "1 2", "-1 2", "-2 0", "-1 -2", "1 -2", "2 0"};
long long length[6];
int searching() {
  long long mid = 0;
  long long l = 1, r = 1e9, temp = 0;
  while (l < r) {
    mid = (l + r) / 2;
    if (6 * (mid) * (mid + 1) / 2 - mid <= n) {
      temp = mid;
      l = mid + 1;
    } else
      r = mid;
  }
  return mid;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  long long cir = searching();
  n -= cir * (cir + 1) * 3 - cir;
  int x = cir, y = -2 * cir;
  if (cir == 0) {
    cout << init[n];
    return 0;
  }
  cir++;
  for (int i = 0; i < 6; i++) length[i] = cir;
  length[1] -= 1;
  for (int i = 0; i < 6; i++) {
    if (n - length[i] > 0) {
      x += ax[i] * (length[i]);
      y += ay[i] * (length[i]);
      n -= length[i];
    } else {
      x += ax[i] * n;
      y += ay[i] * n;
      break;
    }
  }
  cout << x << " " << y;
}
