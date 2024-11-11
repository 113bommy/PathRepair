#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  int a[10005];
  cin >> num;
  int sum = 0;
  for (int i = 0; i < num; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int s, t;
  cin >> s >> t;
  int x, y;
  if (s == t)
    cout << 0 << endl;
  else {
    if (s < t) {
      s = s;
      t = t;
    } else {
      int w = s;
      s = t;
      t = w;
    }
    int cnt = 0;
    for (int i = s - 1; i < t - 1; i++) cnt += a[i];
    x = cnt;
    y = sum - cnt;
    int minn = min(x, y);
    cout << minn << endl;
  }
}
