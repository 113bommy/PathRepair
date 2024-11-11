#include <bits/stdc++.h>
using namespace std;
int v[100002], n;
int rex(int t) {
  int i = 1, j = 1, s = 0, nrc = 0;
  while (j <= n) {
    if (s + v[j] <= t) {
      s += v[j];
      if (nrc < j - i + 1) nrc = j - i + 1;
      j++;
    } else {
      s -= v[i];
      i++;
    }
  }
  return nrc;
}
int main() {
  int t, nrm = 0, j, k, i, s;
  cin >> n >> t;
  for (i = 1; i <= n; i++) {
    cin >> v[i];
  }
  cout << rex(t);
  return 0;
}
