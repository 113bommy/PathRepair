#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0;
  register int f = 1;
  register char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c & 15);
  return x * f;
}
int n;
const int N = 1000000 + 5;
int surprise_mother_fucker_id[N];
int d[N];
int ahskfyhsaihafhsjhjbvjsahjst[N];
inline bool cmp(int x, int y) { return d[x] > d[y]; }
signed main() {
  n = read();
  for (register int i = 1; i <= n; i++)
    surprise_mother_fucker_id[i] = i, d[i] = read();
  sort(surprise_mother_fucker_id + 1, surprise_mother_fucker_id + n + 1, cmp);
  for (register int i = 1; i <= n; i++) {
    ahskfyhsaihafhsjhjbvjsahjst[i] = (surprise_mother_fucker_id[i] << 1);
  }
  int top = n;
  for (register int i = 1; i <= n - 1; i++)
    printf("%d %d\n", ahskfyhsaihafhsjhjbvjsahjst[i],
           ahskfyhsaihafhsjhjbvjsahjst[i + 1]);
  for (register int i = 1; i <= n; i++)
    if (i + d[surprise_mother_fucker_id[i]] > top)
      ahskfyhsaihafhsjhjbvjsahjst[++top] =
          ((surprise_mother_fucker_id[i] << 1) - 1),
      printf("%d %d\n", ahskfyhsaihafhsjhjbvjsahjst[top],
             ahskfyhsaihafhsjhjbvjsahjst[top - 1]);
    else
      printf(
          "%d %d\n", ((surprise_mother_fucker_id[i] << 1) - 1),
          ahskfyhsaihafhsjhjbvjsahjst[i + d[surprise_mother_fucker_id[i]] - 1]);
  return 0;
}
