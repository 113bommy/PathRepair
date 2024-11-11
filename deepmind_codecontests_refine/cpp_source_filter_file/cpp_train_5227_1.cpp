#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 5;
const long long INF = 0x3f3f3f3f;
const int maxm = (1 << 8) + 50;
char s[maxn];
char tmp[maxn];
char now[maxn];
int ul[maxn], ur[maxn];
void change(int l, int r) {
  for (int i = l; i <= r; i++) tmp[i] = s[i];
  for (int i = l; i <= r; i++) s[i] = tmp[r - i + l];
}
void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) now[2 * i - 1] = '(', now[2 * i] = ')';
  for (int i = 2 * k + 1; i <= n / 2 + k; i++) now[i] = '(';
  for (int i = n / 2 + k + 1; i <= n; i++) now[i] = ')';
  now[n + 1] = '\0';
  int cnt = 0;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == now[i]) continue;
    if (s[i] != now[i]) {
      int j = i + 1;
      for (; j <= n; j++)
        if (s[j] == now[i]) break;
      change(i, j);
      ul[++cnt] = i, ur[cnt] = j;
    }
  }
  cout << cnt << endl;
  for (int i = 1; i <= cnt; i++) cout << ul[i] << ' ' << ur[i] << endl;
}
int main(int argc, char *argv[]) {
  if (argc == 2 && strcmp("-debug", argv[1]) == 0) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
