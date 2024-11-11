#include <bits/stdc++.h>
const double pi = acos(-1.0);
using namespace std;
char a[500010];
int b[500010];
int yu[20], huo[20], yihuo[20];
int main() {
  int n;
  cin >> n;
  int c = 0, d = 1023;
  for (int i = 1; i <= n; i++) {
    getchar();
    scanf("%c%d", &a[i], &b[i]);
    if (a[i] == '&') {
      c &= b[i];
      d &= b[i];
    }
    if (a[i] == '|') {
      c |= b[i];
      d |= b[i];
    }
    if (a[i] == '^') {
      c ^= b[i];
      d ^= b[i];
    }
  }
  int cnt = 1;
  for (int i = 1; i <= 10; i++) {
    int cc = c % 2;
    int dd = d % 2;
    if (cc == 0 && dd == 0) {
      yu[cnt] = 0;
      huo[cnt] = 0;
      yihuo[cnt] = 0;
    }
    if (cc == 0 && dd == 1) {
      yu[cnt] = 1;
      huo[cnt] = 0;
      yihuo[cnt] = 0;
    }
    if (cc == 1 && dd == 1) {
      yu[cnt] = 1;
      huo[cnt] = 1;
      yihuo[cnt] = 0;
    }
    if (cc == 1 && dd == 0) {
      yu[cnt] = 1;
      huo[cnt] = 0;
      yihuo[cnt] = 1;
    }
    cnt++;
    c /= 2;
    d /= 2;
  }
  int ans1 = 0, ans2 = 0, ans3 = 0;
  for (int i = 0; i <= 9; i++) {
    ans1 += (pow(2, i) * yu[i + 1]);
    ans2 += (pow(2, i) * huo[i + 1]);
    ans3 += (pow(2, i) * yihuo[i + 1]);
  }
  cout << "3" << endl;
  cout << "& " << ans1 << endl;
  cout << "| " << ans2 << endl;
  cout << "^ " << ans3 << endl;
  return 0;
}
