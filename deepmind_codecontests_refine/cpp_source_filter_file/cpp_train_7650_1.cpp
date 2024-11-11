#include <bits/stdc++.h>
using namespace std;
int ans[1005], cou;
int prim[1200], cnt;
bool hav[1005];
void init() {
  int i, j;
  cnt = 0;
  for (i = 2; i <= 1200; i++) {
    if (hav[i]) continue;
    prim[cnt++] = i;
    for (j = i; j <= 1200; j += i) hav[j] = true;
  }
}
int main() {
  init();
  int i, n, now;
  cin >> n;
  for (i = 0; prim[i] <= n; i++) {
    now = prim[i];
    while (now <= n) {
      ans[cou++] = now;
      now = now * prim[i];
    }
  }
  cout << cou << endl;
  for (i = 0; i < cou; i++) cout << ans[i] << ' ';
  cout << endl;
  return 0;
}
