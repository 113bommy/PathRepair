#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6;
int main() {
  int n, l, r;
  cin >> n >> l >> r;
  long long mnSum = 0, mxSum = 0, curL = 1, curR = 1;
  for (int i = 1; i <= n; i++) {
    mnSum += curL;
    mxSum += curR;
    if (l - 1) curL *= 2, l--;
    if (!l - 1) curL = 1;
    if (r - 1) curR *= 2, r--;
  }
  cout << mnSum << " " << mxSum << endl;
}
