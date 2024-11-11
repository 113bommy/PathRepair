#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 22;
char s[maxn], t[maxn];
int lst[12], n;
int ans;
ll get(char *s) {
  ll res = 0;
  for (int i = 0; s[i]; i++) res = res * 10 + s[i] - '0';
  return res;
}
void check(int x, int y) {
  if (!lst[x] || !lst[y]) return;
  int cnt = 0;
  strcpy(s + 1, t + 1);
  x = lst[x], y = lst[y];
  for (int i = y; i < n; i++) {
    swap(s[i], s[i + 1]);
    cnt++;
  }
  if (x > y) x--;
  for (int i = x; i < n - 1; i++) {
    swap(s[i], s[i + 1]);
    cnt++;
  }
  if (s[1] == '0') {
    int p = -1;
    for (int j = 2; j <= n - 2; j++)
      if (s[j] != '0') {
        p = j;
        break;
      }
    if (p == -1) return;
    cnt += p - 1;
  }
  ans = min(ans, cnt);
}
int main() {
  cin >> t + 1;
  ll val = get(t + 1);
  n = strlen(t + 1);
  if (n == 1) {
    cout << -1 << endl;
  } else {
    strcpy(s + 1, t + 1);
    for (int i = n; i >= 1; i--) {
      if (s[i] == '0' && !lst[0])
        lst[0] = i;
      else if (s[i] == '0' && !lst[10])
        lst[10] = i;
      else if (s[i] == '2' && !lst[2])
        lst[2] = i;
      else if (s[i] == '5' && !lst[5])
        lst[5] = i;
      else if (s[i] == '7' && !lst[7])
        lst[7] = i;
    }
    ans = 100000;
    check(10, 0);
    check(2, 5);
    check(5, 0);
    check(7, 5);
    if (ans == 100000) ans = -1;
    cout << ans << endl;
  }
}
