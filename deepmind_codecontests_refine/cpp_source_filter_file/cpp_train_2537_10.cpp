#include <bits/stdc++.h>
using namespace std;
int n, W, a[110], S;
int main() {
  cout.sync_with_stdio(false);
  cin >> n >> W;
  for (int i = 0; i < n; i++) cin >> a[i], S += a[i];
  if (S < W || W < 1) {
    cout << "No" << endl;
    return 0;
  }
  if (n == 1) {
    if (S == W) {
      cout << "Yes" << endl;
      for (int i = 1; i < W + W; i++) cout << "1 ";
      cout << 1 << endl;
    } else
      cout << "No" << endl;
    return 0;
  }
  if (W == 1) {
    bool flag = false;
    int p = 0;
    for (int i = 0; i < n; i++)
      if (a[i] == 1) {
        flag = true;
        p = i;
        break;
      }
    if (flag) {
      cout << "Yes" << endl;
      cout << p << ' ';
      for (int i = 0; i < n; i++)
        if (i != p)
          while (a[i]) a[i]--, cout << i + 1 << ' ' << i + 1 << ' ';
      cout << p << endl;
    } else
      cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  for (int i = 0; i < n; i++)
    while (W > 2 && a[i] > 1) W--, a[i]--, cout << i + 1 << ' ' << i + 1 << ' ';
  for (int i = 1; i < n - 1; i++)
    while (W > 2 && a[i]) W--, a[i]--, cout << i + 1 << ' ' << i + 1 << ' ';
  cout << "1 ";
  a[0]--;
  for (int i = 1; i < n - 1; i++)
    while (a[i]) a[i]--, cout << i + 1 << ' ' << i + 1 << ' ';
  while (a[n - 1] > 1) a[n - 1]--, cout << n << ' ' << n << ' ';
  cout << "1 " << n << ' ';
  while (a[0]) a[0]--, cout << "1 1 ";
  cout << n << endl;
  return 0;
}
