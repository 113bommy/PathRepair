#include <bits/stdc++.h>
using namespace std;
string itos(int x) {
  stringstream ss;
  ss << x;
  return ss.str();
}
int res, f1;
int n, k, tmp;
int a[200010];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i == k - 1) {
      if (a[i]) f1 = 1;
      a[i] = 0;
    } else if (a[i] == 0)
      a[i] = 1000000007;
  }
  sort(a, a + n);
  for (int i = 1; i < n; i++) {
    tmp += max(0, a[i] - a[i - 1] - 1);
    if (tmp > (n - 1 - i)) {
      res = n - i;
      break;
    } else
      res = tmp;
  }
  cout << min(res + f1, n) << endl;
  return 0;
}
