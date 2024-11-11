#include <bits/stdc++.h>
using namespace std;
int num[10];
void solve() {
  int v, t, mini, minv = 10000000, ans, cnt, ansi;
  scanf("%d", &v);
  for (int i = 1; i < 10; i++) {
    scanf("%d", num + i);
    if (num[i] < minv) {
      minv = num[i];
      mini = i;
    }
  }
  if (v / minv == 0) {
    cout << "-1" << endl;
  } else {
    ans = v % minv;
    cnt = v / minv;
    bool f = true;
    for (int i = 0; i < cnt; i++) {
      if (f) {
        f = false;
        for (int j = 9; j > mini; j--) {
          if (minv + ans >= num[j]) {
            ans = minv + ans - num[j];
            cout << j;
            f = true;
            break;
          }
        }
      }
      if (!f) cout << mini;
    }
    cout << endl;
  }
}
int main() {
  solve();
  return 0;
}
