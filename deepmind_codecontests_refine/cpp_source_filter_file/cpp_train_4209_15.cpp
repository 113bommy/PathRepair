#include <bits/stdc++.h>
using namespace std;
int n, k, i, j, nr, v[1000], x;
int main() {
  cin >> n >> k;
  for (i = 1; i <= n / k; i++) {
    for (j = 1; j <= k; j++) {
      cin >> x;
      if (x == 1) v[j]++;
    }
  }
  for (i = 1; i <= n / k; i++) {
    nr += min(v[i], n / k - v[i]);
  }
  cout << nr;
  return 0;
}
