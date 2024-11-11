#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
int w, l;
int a[100100];
int main() {
  cin >> w >> l;
  int sum = 0;
  for (int i = 1; i <= w - 1; ++i) cin >> a[i];
  for (int i = 1; i <= l; ++i) sum += a[i];
  int pos = l, ans = sum;
  while (pos <= w - l) {
    ans = min(ans, sum);
    pos++;
    sum -= a[pos - l];
    sum += a[pos];
  }
  cout << ans;
  return 0;
}
