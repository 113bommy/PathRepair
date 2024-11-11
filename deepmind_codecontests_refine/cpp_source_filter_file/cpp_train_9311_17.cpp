#include <bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 113;
int n, ans, curr;
int coor[N];
int dpL[N], dpR[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> coor[i];
  }
  coor[n + 1] = 1000000009;
  coor[0] = -1;
  for (int i = 1; i <= n; i++) {
    if (coor[i] > coor[i - 1]) {
      dpL[i] = dpL[i - 1] + 1;
    } else {
      dpL[i] = 1;
    }
  }
  for (int i = n; i > 0; i--) {
    if (coor[i] < coor[i + 1]) {
      dpR[i] = dpR[i + 1] + 1;
    } else {
      dpR[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (coor[i + 1] - coor[i - 1] > 1) {
      curr = dpL[i - 1] + dpR[i + 1] + 1;
    } else {
      curr = max(dpL[i - 1], dpR[i + 1]);
    }
    ans = max(ans, curr);
  }
  cout << ans;
}
