#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  int win[n];
  for (int i = 1; i <= n; ++i) win[i] = 0;
  for (int i = 1; i <= n; ++i) {
    int ma = -1;
    int index = -1;
    for (int j = 1; j <= m; ++j) {
      int a;
      cin >> a;
      if (a > ma) {
        ma = a;
        index = j;
      }
    }
    win[index]++;
  }
  int ma = -1;
  int index = -1;
  for (int i = 1; i <= n; ++i) {
    if (ma < win[i]) {
      ma = win[i];
      index = i;
    }
  }
  cout << index << endl;
  return 0;
}
