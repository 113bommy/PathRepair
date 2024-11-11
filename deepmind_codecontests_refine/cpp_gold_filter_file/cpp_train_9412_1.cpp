#include <bits/stdc++.h>
using namespace std;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-5;
int belong[100005];
int cnt[21];
bitset<(1 << 21)> dead;
int main() {
  int n, m, d;
  scanf("%d %d %d", &n, &m, &d);
  for (int j = 0; j < m; j++) {
    int s;
    scanf("%d", &s);
    for (int k = 0; k < s; k++) {
      int x;
      scanf("%d", &x);
      belong[x] = j;
    }
  }
  int S = (1 << m) - 1;
  int use = 0;
  for (int i = 1; i <= n; i++) {
    cnt[belong[i]]++;
    use |= 1 << belong[i];
    if (i - d >= 1 && --cnt[belong[i - d]] == 0) use ^= 1 << belong[i - d];
    if (i >= d) dead[S ^ use] = true;
  }
  int res = m;
  for (int stt = S; stt >= 0; stt--) {
    if (dead[stt]) {
      for (int j = 0; j < m; j++)
        if ((((stt) >> (j)) & 1)) dead[stt ^ (1 << j)] = true;
    } else {
      int one = 0;
      for (int j = 0; j < m; j++)
        if ((((stt) >> (j)) & 1)) one++;
      res = min(res, one);
    }
  }
  printf("%d\n", res);
  return 0;
}
