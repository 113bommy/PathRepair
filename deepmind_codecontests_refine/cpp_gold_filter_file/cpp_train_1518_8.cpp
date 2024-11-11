#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n, t, k;
int a[MAXN];
int calmin[MAXN], calmax[MAXN];
int main(int argc, const char* argv[]) {
  cin >> n >> t >> k;
  for (int i = 1; i <= t; i++) {
    cin >> a[i];
  }
  int cmin = 0, cmax = 0;
  for (int i = 1; i <= t - 1; i++) {
    calmin[i] = max(0, a[i] - a[i + 1]);
    calmax[i] = a[i] - 1;
    cmin += calmin[i];
    cmax += calmax[i];
  }
  k -= a[t];
  if (k < cmin || k > cmax) {
    cout << "-1" << endl;
    return 0;
  }
  int temp = k - cmin;
  int l = 2, r = 2 + a[1];
  cout << n << endl;
  for (int i = 1; i <= a[1]; i++) {
    cout << "1 " << 1 + i << endl;
  }
  for (int i = 1; i <= t - 1; i++) {
    if (temp > 0) {
      int x = min(temp, calmax[i] - calmin[i]);
      for (int j = 1; j <= a[i] - calmin[i] - x; j++) {
        cout << l + j - 1 << " " << r + j - 1 << endl;
      }
      for (int j = a[i] - calmin[i] - x + 1; j <= a[i + 1]; j++) {
        cout << l << " " << r + j - 1 << endl;
      }
      temp -= x;
    } else {
      for (int j = 1; j <= a[i] - calmin[i]; j++) {
        cout << l + j - 1 << " " << r + j - 1 << endl;
      }
      for (int j = a[i] - calmin[i] + 1; j <= a[i + 1]; j++) {
        cout << l << " " << r + j - 1 << endl;
      }
    }
    l = r;
    r += a[i + 1];
  }
  return 0;
}
