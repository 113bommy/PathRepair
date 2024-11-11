#include <bits/stdc++.h>
using namespace std;
int ara[1000000];
int main() {
  int n;
  int a, b, c;
  cin >> n;
  for (a = 0; a < n; a++) {
    scanf("%d", &ara[a]);
  }
  int cnt = 0, flag = 0, mx = 0, c1, c2, p1, p2;
  for (a = 1; a < n - 1; a++) {
    if (ara[a] != ara[a - 1] && ara[a] != ara[a + 1]) {
      cnt++;
      if (flag == 0) {
        c1 = ara[a - 1];
        p1 = a - 1;
      }
      flag++;
    } else {
      c2 = ara[a + 1];
      p2 = a + 1;
      if (cnt % 2 == 0) {
        for (b = p1 + 1, c = 0; c < cnt / 2; c++, b++) {
          ara[b] = c1;
        }
        for (b = p2 - 1, c = 0; c < cnt / 2; c++, b--) {
          ara[b] = c2;
        }
      } else {
        for (b = p1 + 1, c = 0; c < cnt; c++, b++) {
          ara[b] = c1;
        }
      }
      flag = 0;
      cnt = 0;
    }
    mx = max(mx, cnt);
    if (a == n - 2) {
      c2 = ara[a + 1];
      p2 = a + 1;
      if (cnt % 2 == 0) {
        for (b = p1 + 1, c = 0; c < cnt / 2; c++, b++) {
          ara[b] = c1;
        }
        for (b = p2 - 1, c = 0; c < cnt / 2; c++, b--) {
          ara[b] = c2;
        }
      } else {
        for (b = p1 + 1, c = 0; c < cnt; c++, b++) {
          ara[b] = c1;
        }
      }
      flag = 0;
      cnt = 0;
    }
    mx = max(mx, cnt);
  }
  if (mx % 2 == 0)
    cout << mx / 2 << endl;
  else
    cout << (mx / 2) + 1 << endl;
  for (a = 0; a < n; a++) {
    printf("%d ", ara[a]);
  }
  return 0;
}
