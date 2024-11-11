#include <bits/stdc++.h>
using namespace std;
int a[11], wei;
int D[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int S[11] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
long long ans;
int t;
int bigf;
void jian(int x) {
  for (register int i = x; i <= wei; i += 2) {
    if (a[i] != 0) {
      a[i]--;
      bigf = 1;
      break;
    }
    a[i] = 9;
  }
  if (bigf == 0)
    for (register int i = x; i <= wei; i += 2) {
      a[i] = 0;
    }
  return;
}
void jia(int x) {
  for (register int i = x; i <= wei; i += 2) {
    if (a[i] != 9) {
      a[i]++;
      break;
    }
    a[i] = 0;
  }
  return;
}
void dfs(long long sco, int x) {
  if (sco == 0) return;
  int flag = 1;
  int ten = 1;
  for (register int i = 1; i <= x; i++)
    for (register int i = x; i <= wei; i++) {
      if (a[i] != 0) {
        flag = 0;
        break;
      }
    }
  if (flag) {
    ans += sco;
    return;
  }
  if (x == wei + 1) {
    ans += sco;
    return;
  }
  bigf = 0;
  jian(x + 2);
  if (bigf == 1) {
    dfs(sco * S[a[x]], x + 1);
    jia(x + 2);
  }
  dfs(sco * D[a[x]], x + 1);
  return;
}
int main() {
  int n;
  cin >> n;
  for (register int o = 1; o <= n; o++) {
    cin >> t;
    ans = 0;
    for (int i = 1; i <= 10; i++) {
      a[i] = t % 10;
      t /= 10;
      if (t == 0) {
        wei = i;
        break;
      }
    }
    dfs(1, 1);
    cout << ans - 2 << endl;
  }
  return 0;
}
