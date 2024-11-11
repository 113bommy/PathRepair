#include <bits/stdc++.h>
using namespace std;
int n;
string a, b;
char c[300005], d[300005], ans[300005];
bool cmp(char e, char f) { return e > f; }
int main() {
  ios_base::sync_with_stdio(0);
  cin >> a;
  cin >> b;
  n = a.length();
  for (int i = 0; i < n; i++) c[i] = a[i];
  for (int i = 0; i < n; i++) d[i] = b[i];
  sort(c, c + n);
  sort(d, d + n, cmp);
  for (int i = 0; i < n; i++) ans[i] = '.';
  int turn = 1, i = 0, j = 0, start = 0, finish = n - 1;
  int t, t1;
  if (n % 2)
    t = n / 2, t1 = n / 2 - 1;
  else
    t = n / 2, t1 = n / 2;
  while (n--) {
    if (turn == 1) {
      if (c[i] < d[j])
        ans[start] = c[i], start++, i++;
      else
        ans[finish] = c[t], t--, finish--;
    } else {
      if (c[i] < d[j])
        ans[start] = d[j], start++, j++;
      else
        ans[finish] = d[t1], t1--, finish--;
    }
    turn = 3 - turn;
  }
  for (int i = 0; i < a.length(); i++) cout << ans[i];
}
