#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d;
  cin >> n >> d;
  vector<int> pts(n), curr(n);
  for (int i = 0; i < n; i++) {
    cin >> curr[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> pts[i];
  }
  int max = curr[d - 1] + pts[0];
  for (int i = 0; i < n; i++) {
    curr[i] = max - curr[i];
  }
  sort(pts.begin(), pts.end());
  int strt = 0, ind = 0, flag = 0;
  for (int i = 0; i < d - 1; i++) {
    if (ind == d - 1) {
      flag = 1;
      break;
    }
    if (curr[ind] >= pts[i]) {
      ind++;
      continue;
    }
    while (curr[ind] < pts[i]) {
      if (ind == d - 1) {
        flag = 2;
        break;
      }
      ind++;
      strt++;
    }
    ind++;
  }
  cout << strt + 1;
}
