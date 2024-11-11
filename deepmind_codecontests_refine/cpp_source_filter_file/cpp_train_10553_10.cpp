#include <bits/stdc++.h>
using namespace std;
int N, M, s[1000005][4][4];
char a[1000005], b[1000005];
void init() {
  scanf("%s%s", a + 1, b + 1), N = strlen(a + 1), M = strlen(b + 1);
  for (int i = 1; i <= N; i++) a[i] = a[i] == 'R' ? 1 : a[i] == 'B' ? 2 : 3;
  for (int i = 1; i <= M; i++) b[i] = b[i] == 'R' ? 1 : b[i] == 'B' ? 2 : 3;
  for (int i = 1; i <= M; i++)
    memcpy(s[i], s[i - 1], sizeof(s[i])), s[i][b[i - 1]][b[i]]++;
}
void doit() {
  long long ans = 0;
  for (int i = 1, l = 1, r = 1; i <= N && l <= M; i++) {
    for (; r < M && b[r] != a[i]; r++)
      ;
    ans += r - l + 1;
    if (a[i] != a[i + 1])
      ans -= s[r + 1][a[i]][a[i + 1]] - s[l + 1][a[i]][a[i + 1]];
    if (a[i] == b[l]) l++;
    if (r < M) r++;
  }
  cout << ans << endl;
}
int main() {
  init();
  doit();
  return 0;
}
