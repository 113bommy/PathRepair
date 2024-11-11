#include <bits/stdc++.h>
using namespace std;
int boy[100 + 10];
int girl[100 + 10];
int n, m, b, g;
int main() {
  while (scanf("%d%d", &n, &m) != EOF) {
    memset(boy, 0, sizeof(boy));
    memset(girl, 0, sizeof(girl));
    cin >> b;
    int x;
    for (int i = 0; i < b; i++) {
      cin >> x;
      boy[x] = 1;
    }
    cin >> g;
    for (int i = 0; i < g; i++) {
      cin >> x;
      girl[x] = 1;
    }
    int ok = 1;
    int tot = n * m * 100;
    for (int i = 0; i < tot; i++) {
      if (boy[i % n])
        girl[i % m] = 1;
      else if (girl[i % m])
        boy[i % n] = 1;
    }
    for (int i = 0; i < n; i++)
      if (!boy[i]) {
        ok = 0;
        break;
      }
    for (int i = 0; i < m; i++)
      if (!girl[i]) {
        ok = 0;
        break;
      }
    if (ok)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
