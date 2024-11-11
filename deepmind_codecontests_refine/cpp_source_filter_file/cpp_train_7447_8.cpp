#include <bits/stdc++.h>
using namespace std;
int n, k, h, x, curHeight, secs;
int main() {
  cin >> n >> h >> k;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (curHeight + x > h) {
      secs += curHeight / k;
      curHeight -= k * (curHeight / k);
    }
    if (curHeight + x > h) {
      secs++;
      curHeight = 0;
    }
    curHeight += x;
  }
  cout << secs + (curHeight + k - 1) / k << endl;
}
