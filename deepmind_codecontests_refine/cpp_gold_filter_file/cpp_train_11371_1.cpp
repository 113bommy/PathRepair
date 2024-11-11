#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int cnt = 0;
struct pp {
  int n;
  string s;
} ans[3100];
void printcrrow() {
  ans[++cnt].n = 1;
  ans[cnt].s += "D";
  ans[++cnt].n = m - 1;
  ans[cnt].s += "R";
  ans[++cnt].n = m - 1;
  ans[cnt].s += "UDL";
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (k > 2 * n * (m - 1) + 2 * m * (n - 1)) {
    printf("NO\n");
    return 0;
  } else
    printf("YES\n");
  cnt = 0;
  if (k <= 2 * (m - 1)) {
    if (k <= m - 1) {
      ans[++cnt].n = k;
      ans[cnt].s += "R";
    } else {
      ans[++cnt].n = m - 1;
      ans[cnt].s += "R";
      ans[++cnt].n = k - (m - 1);
      ans[cnt].s += "L";
    }
  } else if (k <= (m - 1) * 2 + (n - 1) * (1 + (m - 1) * 4)) {
    ans[++cnt].n = m - 1;
    ans[cnt].s += "R";
    ans[++cnt].n = m - 1;
    ans[cnt].s += "L";
    int rest = k - (m - 1) * 2;
    int pcr = 1 + (m - 1) * 4;
    int introw = rest / pcr;
    for (int i = 1; i <= introw; i++) {
      printcrrow();
    }
    rest = rest % pcr;
    if (rest == 0) {
      ;
    } else if (rest == 1) {
      ans[++cnt].n = 1;
      ans[cnt].s += "D";
    } else if (rest <= m) {
      ans[++cnt].n = 1;
      ans[cnt].s += "D";
      rest--;
      ans[++cnt].n = rest;
      ans[cnt].s += "R";
    } else {
      ans[++cnt].n = 1;
      ans[cnt].s += "D";
      ans[++cnt].n = m - 1;
      ans[cnt].s += "R";
      rest -= m;
      ans[++cnt].n = rest / 3;
      ans[cnt].s += "UDL";
      if (rest % 3 == 1) {
        ans[++cnt].n = 1;
        ans[cnt].s += "U";
      } else if (rest % 3 == 2) {
        ans[++cnt].n = 1;
        ans[cnt].s += "UD";
      }
    }
  } else {
    ans[++cnt].n = m - 1;
    ans[cnt].s += "R";
    ans[++cnt].n = m - 1;
    ans[cnt].s += "L";
    for (int i = 1; i < n; i++) printcrrow();
    int rest = k - ((m - 1) * 2 + (n - 1) * (1 + (m - 1) * 4));
    ans[++cnt].n = rest;
    ans[cnt].s += "U";
  }
  int anscnt = 0;
  for (int i = 1; i <= cnt; i++) {
    if (ans[i].n != 0) anscnt++;
  }
  printf("%d\n", anscnt);
  for (int i = 1; i <= cnt; i++) {
    if (ans[i].n != 0) cout << ans[i].n << ' ' << ans[i].s << endl;
  }
  return 0;
}
