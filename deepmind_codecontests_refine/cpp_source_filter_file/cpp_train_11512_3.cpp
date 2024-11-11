#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 100;
int date[N];
int q[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &date[i]);
  }
  int cnt = 0, bef = 0, last = 0;
  bool te = true;
  for (int i = 1; i <= n; i++) {
    if (date[i] >= 0) continue;
    last = i;
    te = false;
    if (bef == 0) {
      bef = i;
    } else {
      q[cnt++] = i - bef - 1;
      bef = i;
    }
  }
  if (te) {
    cout << 0 << endl;
  } else if (k < cnt + 1) {
    cout << -1 << endl;
  } else {
    int cnts = cnt * 2 + 2;
    sort(q, q + cnt);
    int nowk = k - (cnt + 1);
    for (int i = 0; i < cnt; i++) {
      if (k >= q[i]) {
        nowk -= q[i];
        cnts -= 2;
      } else
        break;
    }
    if (n - last <= nowk) cnts -= 1;
    cout << cnts << endl;
  }
  return 0;
}
