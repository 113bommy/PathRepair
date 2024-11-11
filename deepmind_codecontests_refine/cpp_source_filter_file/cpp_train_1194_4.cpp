#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void chkmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
char s[100005];
char pat[] = "ACGT";
int cnt[15];
int main() {
  int i, n;
  scanf("%d", &n);
  scanf("%s", s);
  for (i = 0; i < n; i++) {
    cnt[strchr(pat, s[i]) - pat]++;
  }
  int mx = 0;
  for (i = 0; i < 4; i++) chkmax(mx, cnt[i]);
  int tot = 0;
  for (i = 0; i < 4; i++)
    if (mx == cnt[i]) tot++;
  int ans = 1;
  for (i = 0; i < n; i++) ans = ans * tot % 1000000007;
  cout << ans << endl;
  return 0;
}
