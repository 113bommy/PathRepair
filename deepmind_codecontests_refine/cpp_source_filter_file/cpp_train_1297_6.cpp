#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 5;
const int MAXM = 20;
long long identity[1 << MAXM];
int n;
char s[MAXN][MAXM + 10];
int main() {
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  int len = strlen(s[0]);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int mask = 0;
      for (int k = 0; k < len; k++) {
        if (s[i][k] == s[j][k]) {
          mask |= (1 << k);
        }
      }
      identity[mask] |= (1 << i) | (1 << j);
    }
  }
  for (int mask = (1 << len) - 1; mask >= 0; mask--) {
    for (int i = 0; i < len; i++) {
      if ((mask >> i) & 1) {
        identity[mask ^ (1 << i)] |= identity[mask];
      }
    }
  }
  long double ans = 0;
  for (int mask = 0; mask < (1 << len); mask++) {
    int moves = __builtin_popcount(mask) + 1;
    for (int k = 0; k < len; k++) {
      if (!((mask >> k) & 1)) {
        long long dif = identity[mask] ^ identity[mask ^ (1 << k)];
        if (dif == 0) continue;
        int cnt = __builtin_popcountll(dif);
        long double curexp = cnt * moves;
        for (int i = 0; i < moves - 1; i++) {
          curexp *= (long double)(moves - i - 1) / (long double)(len - i);
        }
        curexp /= (long double)(len - moves + 1);
        ans += curexp;
      }
    }
  }
  ans /= (long double)n;
  cout << fixed << setprecision(15) << ans << endl;
}
