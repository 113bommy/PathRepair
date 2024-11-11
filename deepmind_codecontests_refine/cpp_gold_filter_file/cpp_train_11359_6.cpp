#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  long long cnt = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  int x, f;
  cin >> x >> f;
  for (int i = 0; i < n; i++) {
    a[i] -= x;
    if (a[i] > 0) {
      int k = a[i] / (x + f);
      if (a[i] - k * (x + f)) k++;
      cnt += k;
    }
  }
  cout << cnt * f;
}
