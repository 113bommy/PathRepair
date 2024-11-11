#include <bits/stdc++.h>
using namespace std;
int m;
int total = 0;
int a[105];
int x, y;
int main() {
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    total += a[i];
  }
  cin >> x >> y;
  int cnt = 0;
  for (int i = 0; i < m; i++) {
    cnt += a[i];
    if (cnt >= x && cnt <= y && total - cnt >= x && total - cnt <= y) {
      cout << i + 2;
      return 0;
    }
  }
  cout << 0;
  return 0;
}
