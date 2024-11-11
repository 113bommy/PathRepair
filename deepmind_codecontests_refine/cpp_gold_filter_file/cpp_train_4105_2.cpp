#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, max1, max2, maxid1, maxid2, a;
  cin >> n;
  cin >> max1;
  cin >> max2;
  maxid1 = 1;
  maxid2 = 2;
  if (max2 > max1) {
    a = max1;
    max1 = max2;
    max2 = a;
    maxid1 = 2;
    maxid2 = 1;
  }
  for (int i = 3; i <= n; i++) {
    cin >> a;
    if (a > max1) {
      maxid2 = maxid1;
      max2 = max1;
      max1 = a;
      maxid1 = i;
    } else if (a > max2) {
      max2 = a;
      maxid2 = i;
    }
  }
  cout << maxid1 << ' ' << max2;
  return 0;
}
