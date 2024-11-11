#include <bits/stdc++.h>
using namespace std;
int a[2000050];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[0] = -1;
  a[n + 1] = -1;
  int minn = 1e9;
  int maxx = 0;
  bool flag = false;
  if (a[1] != -1) {
    if (a[2] == -1) {
      minn = min(minn, a[1]);
      maxx = max(maxx, a[1]);
      flag = true;
    }
  }
  for (int i = 2; i <= n - 1; i++) {
    if (a[i] != -1 && (a[i - 1] == -1 || a[i + 1] == -1)) {
      minn = min(minn, a[i]);
      maxx = max(maxx, a[i]);
      flag = true;
    }
  }
  if (a[n] != -1) {
    if (a[n - 1] == -1) {
      minn = min(minn, a[1]);
      maxx = max(maxx, a[1]);
      flag = true;
    }
  }
  int x;
  if (flag)
    x = (minn + maxx) >> 1;
  else
    x = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] == -1) a[i] = x;
  maxx = 0;
  if (n == 2) {
    maxx = a[2] - a[1];
  } else
    for (int i = 2; i <= n - 1; i++) {
      maxx = max(maxx, abs(a[i] - a[i - 1]));
      maxx = max(maxx, abs(a[i] - a[i + 1]));
    }
  cout << maxx << " " << x << endl;
}
int main() {
  int TT;
  cin >> TT;
  while (TT--) solve();
  return 0;
}
