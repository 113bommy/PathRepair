#include <bits/stdc++.h>
using namespace std;
int n, cnt, ans;
pair<double, double> P[100010];
double del[100010];
int C[2020];
bool iss(double a, double b) { return abs(a - b) <= 1e-20; }
int C2(int a) { return (a - 1) * a / 2; }
bool operator!=(const pair<double, double>& a, const pair<double, double>& b) {
  return !(abs(a.first - b.first) <= 1e-20 &&
           abs(a.second - b.second) <= 1e-20);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (a == 0)
      P[i] = {0, c / b};
    else if (b == 0)
      P[i] = {c / a, 0};
    else
      P[i] = {(c * a) / (a * a + b * b), (b * c) / (a * a + b * b)};
  }
  for (int i = 1; i < n; i++) {
    cnt = 0;
    int sam = 1;
    for (int j = i + 1; j <= n; j++) {
      if (P[i] != P[j]) {
        if (!iss(P[i].first, P[j].first))
          del[++cnt] = (P[j].second - P[i].second) / (P[j].first - P[i].first);
        else
          del[++cnt] = 1e30;
      } else {
        sam++;
      }
    }
    sort(del + 1, del + 1 + cnt);
    int nowp = 2;
    double lst = del[1];
    int fcnt = 1;
    while (nowp <= cnt) {
      if (!iss(lst, del[nowp])) {
        if (fcnt != 1) ans += C2(fcnt);
        fcnt = 1;
        lst = del[nowp];
      } else
        fcnt++;
      nowp++;
    }
    if (fcnt != 1) ans += C2(fcnt);
    ans += (sam - 1) * (cnt);
  }
  printf("%d\n", ans);
}
