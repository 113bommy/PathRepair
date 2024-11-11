#include <bits/stdc++.h>
using namespace std;
int a[1000002] = {0};
int las[1000002] = {0};
int nxt[1000002] = {0};
int beg[1000002] = {0};
int n, k, l, r, ansl, ansr = -1, cnt;
int main() {
  int i;
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (!beg[a[i]]) beg[a[i]] = i;
    if (las[a[i]]) nxt[las[a[i]]] = i;
    las[a[i]] = i;
  }
  for (i = 1; i < 1000002; i++) las[i] = 0;
  for (l = 1; l <= n; l++) {
    while (cnt <= k && r <= n) {
      r++;
      if (!las[a[r]]) {
        las[a[r]] = r;
        cnt++;
      }
    }
    las[a[r]] = 0;
    r--;
    cnt--;
    if (r - l > ansr - ansl) {
      ansl = l;
      ansr = r;
    }
    las[a[l]] = nxt[l];
    if (las[a[l]] == 0 || las[a[l]] > r) {
      las[a[l]] = 0;
      cnt--;
    }
  }
  printf("%d %d\n", ansl, ansr);
  return 0;
}
