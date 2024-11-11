#include <bits/stdc++.h>
using namespace std;
int const MAX = 1000 * 100 + 10;
int const MAX2 = 1000 * 1000 + 10;
int const MAX3 = 5000 + 10;
bool mark[MAX];
int in[MAX];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n, x;
  cin >> n >> x;
  int ans = 0;
  for (int i = 1; i <= n; i++) cin >> in[i], mark[in[i]] = 1;
  if (mark[x] == 0) ans++, n++, in[n] = x;
  sort(in + 1, in + n + 1);
  int temp = 0;
  for (int i = 1; i <= n; i++) {
    if (in[i] == x) temp = i;
  }
  while (temp > (n + 1) / 2 && in[temp - 1] == x) temp--;
  if (in[(n + 1) / 2] == x) {
    cout << 0;
    return 0;
  }
  if (temp >= (n + 1) / 2)
    cout << ans - (n - temp - (temp - 1));
  else
    cout << ans - (temp - 1 - (n - temp)) - 1;
}
