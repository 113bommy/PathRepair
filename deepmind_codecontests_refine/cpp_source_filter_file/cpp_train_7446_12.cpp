#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 5;
char s[MAX];
int main() {
  int n, a, b, T;
  cin >> n >> a >> b >> T;
  vector<int> t(2 * n);
  long long sum = 0;
  int l = 1, r = n, res = 0;
  scanf("%s", s);
  for (int i = 0; i < n; i++) {
    if (s[i] == 'w')
      t[i] = t[i + n] = b + 1;
    else
      t[i] = t[i + n] = 1;
    sum += t[i];
  }
  sum -= t[0];
  while (l <= n && r < 2 * n) {
    sum += t[r++];
    while (r - l > n || sum + (r - l - 1 + min(n - l, r - n - 1) * a) > T)
      sum -= t[l++];
    if (l > n) break;
    res = max(r - l, res);
  }
  cout << res << endl;
  return 0;
}
