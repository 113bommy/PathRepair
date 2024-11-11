#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n;
  cin >> m >> n;
  vector<int> judge(n);
  for (int i = 0; i < n; ++i) {
    int j;
    cout << 1 << endl;
    cin >> j;
    if (j == 0) {
      return 0;
    } else if (j == 1) {
      judge[i] = 1;
    }
  }
  int now = 0;
  int l = 1;
  int r = m;
  int mid = r;
  for (int i = 0; i < 30; ++i) {
    int j;
    mid = (l + r) / 2;
    cout << mid << endl;
    cin >> j;
    if (judge[now % n]) {
      if (j == 1) {
        l = mid + 1;
      } else if (j == -1) {
        r = mid - 1;
      } else if (j == 0) {
        return 0;
      }
    } else {
      if (j == 1) {
        r = mid - 1;
      } else if (j == -1) {
        l = mid + 1;
      } else if (j == 0) {
        return 0;
      }
    }
    now++;
  }
  return 0;
}
