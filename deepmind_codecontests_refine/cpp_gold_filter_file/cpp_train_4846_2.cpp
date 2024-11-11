#include <bits/stdc++.h>
using namespace std;
int n, k, f[1000001], kt[1000001], cnt[1000001];
int main() {
  ios_base::sync_with_stdio(false);
  ;
  f[0] = f[1] = 1;
  for (int i = (2); i <= (1000000); i++)
    if (f[i] == 0)
      for (int j = 1; i * j <= 1000000; j++) f[i * j] = i;
  cin >> n >> k;
  while (k != 1) {
    int x = f[k], cntt = 0;
    while (k % x == 0) k /= x, cntt++;
    cnt[x] = cntt;
  }
  for (int i = (1); i <= (n); i++) {
    int res;
    cin >> res;
    while (res != 1) {
      int x = f[res], cntt = 0;
      while (res % x == 0) res /= x, ++cntt;
      if (cnt[x] > 0 && cntt >= cnt[x]) kt[x] = 1;
    }
  }
  for (int i = (1); i <= (1000000); i++)
    if (cnt[i] > 0 && kt[i] == 0) {
      cout << "No";
      return 0;
    }
  cout << "Yes" << endl;
}
