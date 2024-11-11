#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int n, L;
int a[1 << 7], b[1 << 7];
int sum(int a, int b) {
  a += b;
  while (a >= 1000000007) a -= 1000000007;
  return a;
}
int mem[1 << 7][1 << 1][1 << 12];
int get(int deskId, int sw, int len) {
  int w = a[deskId];
  int h = b[deskId];
  if (sw) swap(w, h);
  int remLen = len - w;
  if (remLen < 0) return 0;
  if (remLen == 0) return 1;
  int& res = mem[deskId][sw][len];
  if (res == -1) {
    res = 0;
    for (int i = 0; i < (int)(n); ++i) {
      if (i == deskId) continue;
      if (a[i] == b[i]) {
        if (a[i] == h) res = res + get(i, 0, remLen);
      } else {
        if (a[i] == h) res = sum(res, get(i, 0, remLen));
        if (b[i] == h) res = sum(res, get(i, 1, remLen));
      }
    }
  }
  return res;
}
int main() {
  memset(mem, -1, sizeof(mem));
  cin >> n >> L;
  for (int i = 0; i < (int)(n); ++i) cin >> a[i] >> b[i];
  int res = 0;
  for (int i = 0; i < (int)(n); ++i) {
    res = sum(res, get(i, 0, L));
    if (a[i] != b[i]) {
      res = sum(res, get(i, 1, L));
    }
  }
  cout << res << endl;
  return 0;
}
