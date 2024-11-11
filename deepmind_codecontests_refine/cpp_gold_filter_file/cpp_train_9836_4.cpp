#include <bits/stdc++.h>
using namespace std;
int n, a[300000], b[300000], sumw, maxh, ansmaxh, anssum, r;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    sumw = sumw + a[i];
    if (maxh < b[i]) {
      maxh = b[i];
      r = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    anssum = sumw;
    anssum = sumw - a[i];
    if (r != i)
      cout << anssum * b[r] << "  ";
    else {
      for (int j = 1; j <= n; j++)
        if (j != i) ansmaxh = max(ansmaxh, b[j]);
      cout << ansmaxh * anssum << "  ";
      ansmaxh = 0;
    }
  }
}
