#include <bits/stdc++.h>
using namespace std;
const int MAXH = 5;
const int MAXM = 11;
const int MAXN = 21;
int n, t;
int f[MAXN][MAXM][MAXH][MAXH];
bool Input(void) {
  if (EOF == scanf("%d %d", &n, &t)) {
    return false;
  }
  return true;
}
inline int Opt(int len, int cnt, int HL, int HR) {
  int &ans = f[len][cnt][HL][HR];
  if (-1 != ans) {
    return ans;
  }
  if (1 == cnt) {
    ans = 0;
    for (int topIdx = 2; topIdx < len; topIdx++) {
      for (int topH = 2; topH <= 4; topH++) {
        int tmp = 0;
        if (topIdx - 1 > topH - HL || len - topIdx > topH - HR) {
          continue;
        }
        if (topIdx - 1 == 2 && topH - HL == 3) {
          tmp += 2;
        }
        if (len - topIdx == 2 && topH - HR == 3) {
          tmp += 2;
        }
        if (!tmp) {
          tmp += 1;
        }
        ans += tmp;
      }
    }
    return ans;
  }
  ans = 0;
  for (int k = 1; k < len; k++) {
    for (int L = 1; L <= 4; L++) {
      ans += Opt(len - k, cnt - 1, HL, L) * Opt(k + 1, 1, L, HR);
    }
  }
  return ans;
}
int Process(void) {
  int ans = 0;
  for (int hl = 1; hl <= 4; hl++) {
    for (int hr = 1; hr <= 4; hr++) {
      ans += Opt(n, t, hl, hr);
    }
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  memset(f, -1, sizeof(f));
  while (true == Input()) {
    printf("%d\n", Process());
  }
  return 0;
}
