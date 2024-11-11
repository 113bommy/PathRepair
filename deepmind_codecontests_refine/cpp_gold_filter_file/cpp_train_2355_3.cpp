#include <bits/stdc++.h>
using namespace std;
int lowbit(int x) { return x & (-x); }
int main() {
  int n, x;
  cin >> n >> x;
  int res[100005];
  if (n == 2 && x == 0)
    cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    if (n == 1)
      cout << x << endl;
    else if (n == 2)
      cout << "0 " << x << endl;
    else {
      for (int i = 1; i <= n - 1; i++) res[i] = i;
      res[n - 1] += 131072, res[n] = x;
      for (int i = 1; i <= n - 1; i++) res[n] ^= res[i];
      if (res[n] == res[n - 1]) {
        res[n] += 262144;
        res[n - 2] += 262144;
      }
      for (int i = 1; i <= n; i++) cout << res[i] << " ";
      cout << endl;
    }
  }
  return 0;
}
