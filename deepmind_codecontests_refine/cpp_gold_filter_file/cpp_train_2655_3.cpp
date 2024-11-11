#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int* a = new int[n + 1];
  vector<bool> b = vector<bool>(n + 1, true);
  int k;
  int curPos = -1;
  int dir = 1;
  int changes = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &k);
    a[i] = k;
    if (curPos == -1 && k == 0) curPos = i;
  }
  b[curPos] = false;
  for (int j = 1; j < n; ++j) {
    bool needsChange = true;
    for (int t = curPos + dir; t <= n && t >= 1; t += dir)
      if (a[t] <= j && b[t]) {
        curPos = t;
        b[t] = false;
        needsChange = false;
        break;
      }
    if (needsChange) {
      ++changes;
      dir *= -1;
      for (int t = curPos + dir; t <= n && t >= 1; t += dir)
        if (a[t] <= j && b[t]) {
          curPos = t;
          b[t] = false;
          break;
        }
    }
  }
  printf("%d", changes);
  return false;
}
