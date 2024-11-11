#include <bits/stdc++.h>
using namespace std;
long long n, m, k, i, j, a[1000001], maxnm, ans[1000000], b[1000000], ind, res;
int main() {
  cin >> n >> k;
  a[0] = -1;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 0; i <= n; i++) {
    if (a[i] != a[i + 1]) {
      m++;
      b[m] = a[i + 1];
    }
  }
  for (i = 2; i <= m - 1; i++) {
    if (b[i - 1] == b[i + 1]) {
      ans[b[i]] += 2;
    } else {
      ans[b[i]]++;
    }
  }
  ans[b[1]]++;
  ans[b[m]]++;
  res = -1;
  for (i = 1; i <= k; i++)
    if (ans[i] > res) {
      res = ans[i];
      ind = i;
    }
  cout << ind;
}
