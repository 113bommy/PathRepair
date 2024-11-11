#include <bits/stdc++.h>
using namespace std;
int vis[100100];
vector<int> vv;
int main() {
  int n, k, xx, b;
  scanf("%d", &n), scanf("%d", &k);
  scanf("%d", &b);
  vis[b]++;
  vv.push_back(b);
  for (int i = (1); i < (int)(n); ++i) {
    while (i < n && scanf("%d", &xx) && xx == b) i++;
    if (xx != b) vv.push_back(b);
    b = xx;
  }
  n = ((int)((vv).size()));
  for (int i = (1); i < (int)(k + 1); ++i) vis[i] = n - 1;
  for (int i = (0); i < (int)(n); ++i) {
    vis[vv[i]]--;
    if (i == 0 || i == n - 1) continue;
    if (vv[i - 1] == vv[i + 1]) vis[vv[i]]--;
  }
  int ans = 1000000000, inx = -1;
  for (int i = (1); i < (int)(k + 1); ++i)
    if (ans > vis[i]) {
      ans = vis[i];
      inx = i;
    }
  printf("%d", inx);
  return 0;
}
