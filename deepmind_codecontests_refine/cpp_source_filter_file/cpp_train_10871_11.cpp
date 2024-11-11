#include <bits/stdc++.h>
using namespace std;
const int N = 20000;
int x[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i];
  sort(x, x + n);
  int ans = N;
  int d = 0;
  int first = 0;
  for (int i = 0; i < N; i++) {
    int l = N;
    int r = -N;
    for (int j = 0; j < n; j++) {
      r = max(r, -j * i + x[j]);
      l = min(l, -j * i + x[j]);
    }
    int temp = (r - l + 1) / 2;
    if (temp < ans) {
      ans = temp;
      d = i;
      first = l + ans;
    }
  }
  cout << ans << endl;
  cout << first << " " << d << endl;
  return 0;
}
