#include <bits/stdc++.h>
using namespace std;
constexpr auto MAX = 100228;
long long a[MAX];
char tp[MAX];
int main(void) {
  ios::sync_with_stdio(false);
  int n;
  long long c, d, ans, last, s;
  cin >> n >> c >> d;
  for (int i = 0; i < n; i++) cin >> a[i] >> tp[i];
  cin >> a[n];
  tp[n] = 'X';
  ans = d * n;
  last = a[n];
  for (int i = n - 1; i >= 0; i--) {
    if (tp[i] == tp[i + 1])
      s += min(d, last - a[i + 1] * c);
    else
      last = a[i + 1];
    ans = min(ans, c * (a[n] - a[i]) + s + d * i);
  }
  cout << ans << endl;
  return 0;
}
