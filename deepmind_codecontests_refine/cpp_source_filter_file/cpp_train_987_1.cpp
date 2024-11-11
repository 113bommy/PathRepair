#include <bits/stdc++.h>
using namespace std;
struct man {
  long long int m, s, I;
};
man a[131072];
bool cmp(man a, man b) {
  if (a.m < b.m) return true;
  if (a.m > b.m) return false;
  if (a.I > b.I) return true;
  if (a.I < b.I) return false;
}
int main() {
  queue<man> x;
  long long int n, d, i, tbr = 0, maxbr = 0;
  cin >> n >> d;
  for (i = 0; i < n; i++) {
    cin >> a[i].m >> a[i].s;
    a[i].I = i;
  }
  sort(a, a + n, cmp);
  for (i = 0; i < n; i++) {
    x.push(a[i]);
    struct man m = x.front(), m2 = x.back();
    while (m2.m - m.m > d) {
      tbr -= m.s;
      x.pop();
      m = x.front();
      m2 = x.back();
    }
    tbr += m2.s;
    if (tbr > maxbr) maxbr = tbr;
  }
  cout << maxbr << endl;
  return 0;
}
