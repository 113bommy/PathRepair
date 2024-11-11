#include <bits/stdc++.h>
using namespace std;
double a[3];
struct node {
  double x;
  int id;
  char s[20];
} ans[123];
int mx[] = {0, 1, 2, 5, 6, 9, 10};
int my[] = {0, 3, 4, 7, 8, 11, 12};
char en[] = {'x', 'y', 'z'};
bool cmp(node a, node b) {
  if (fabs(a.x - b.x) < 1e-10) return a.id < b.id;
  return a.x > b.x;
}
int flag = 0;
int main() {
  cin >> a[en[0] - 'x'] >> a[en[1] - 'x'] >> a[en[2] - 'x'];
  if (a[en[0] - 'x'] < 1 && a[en[1] - 'x'] < 1 && a[en[2] - 'x'] < 1) flag = 1;
  int T = 6, t = 0;
  while (T--) {
    if (!flag)
      ans[t].x = (a[en[0] - 'x'] < 1) ? -0x3f3f3f3f
                                      : a[en[2] - 'x'] * log10(a[en[1] - 'x']) +
                                            log10(log10(a[en[0] - 'x']));
    else
      ans[t].x = pow(a[en[0] - 'x'], pow(a[en[1] - 'x'], a[en[2] - 'x']));
    ans[t].s[0] = en[0];
    ans[t].s[2] = en[1];
    ans[t].s[4] = en[2];
    ans[t].s[1] = ans[t].s[3] = '^';
    ans[t].s[5] = 0;
    ans[t++].id = mx[6 - T];
    if (!flag)
      ans[t].x =
          (a[en[0] - 'x'] < 1)
              ? -0x3f3f3f3f
              : log10(a[en[2] - 'x'] * a[en[1] - 'x'] * log10(a[en[0] - 'x']));
    else
      ans[t].x = pow(a[en[0] - 'x'], a[en[1] - 'x'] * a[en[2] - 'x']);
    ans[t].s[1] = en[0];
    ans[t].s[3] = en[1];
    ans[t].s[6] = en[2];
    ans[t].s[0] = '(';
    ans[t].s[2] = ans[t].s[5] = '^';
    ans[t].s[4] = ')';
    ans[t].s[7] = 0;
    ans[t++].id = my[6 - T];
    next_permutation(en, en + 3);
  }
  sort(ans, ans + 12, cmp);
  cout << ans[0].s << endl;
  return 0;
}
