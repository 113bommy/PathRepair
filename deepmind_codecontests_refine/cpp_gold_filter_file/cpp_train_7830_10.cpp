#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  string p;
  cin >> n >> p;
  queue<int> q;
  int b = 0;
  for (int i = 0; i < n; i++) {
    b += p[i] == '(' ? 1 : -1;
    if (!b) {
      q.push(i);
    }
  }
  if (b) {
    printf("-1\n");
    return 0;
  } else {
    int s = 0, ans = 0;
    while (!q.empty()) {
      int e = q.front();
      q.pop();
      int b = 0;
      for (int i = s; i <= e; i++) {
        b += p[i] == '(' ? 1 : -1;
        if (b < 0) {
          ans += e - s + 1;
          break;
        }
      }
      s = e + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
