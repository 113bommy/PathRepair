#include <bits/stdc++.h>
using namespace std;
int maximum(int a, int b) {
  if (a > b)
    return a;
  else
    return b;
}
bool cmp(const pair<int, int>& firs, const pair<int, int>& sec) {
  return firs.first < sec.first;
}
int x[105], y[105], n;
int mem[101][601][601];
int sol(int idx, int sr, int sl) {
  if (idx == n && sr % 2 == 0 && sl % 2 == 0) return 0;
  if (idx == n && (sr % 2 != 0 || sl % 2 != 0)) return 1000000000;
  if (mem[idx][sr][sl] != -1) return mem[idx][sr][sl];
  int ans, z1, z2;
  z1 = sol(idx + 1, sr + x[idx], sl + y[idx]);
  z2 = 1 + sol(idx + 1, sr + y[idx], sl + x[idx]);
  ans = min(z1, z2);
  mem[idx][sr][sl] = ans;
  return ans;
}
int main() {
  int i, sx, sy;
  memset(mem, -1, sizeof(mem));
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    sx += x[i];
    scanf("%d", &y[i]);
    sy += y[i];
  }
  if (sx % 2 == 0 && sy % 2 == 0)
    printf("%d\n", 0);
  else {
    int z = 0;
    z = sol(0, 0, 0);
    if (z >= 1000000000)
      printf("%d\n", -1);
    else
      printf("%d\n", z);
  }
  return 0;
}
