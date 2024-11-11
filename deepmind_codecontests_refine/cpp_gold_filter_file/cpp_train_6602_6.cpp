#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
pair<int, int> ms[100100], fila[100100], as[100100], bs[100100];
void gablah() {
  for (int i = 0; i < a; ++i) {
    int q =
        lower_bound(bs, bs + b, make_pair(as[i].first - 1, as[i].second)) - bs;
    if (q < b)
      as[i].first = max(as[i].first, bs[q].second);
    else
      as[i].first = n + 1;
  }
  b = 0;
  for (int i = 0; i < a; ++i) {
    if (as[i].first <= as[i].second)
      bs[b++] = make_pair(as[i].second, as[i].first);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) scanf("%d%d", &ms[i].first, &ms[i].second);
  sort(ms, ms + m);
  bs[0] = make_pair(1, 1);
  b = 1;
  int ant = 0, nex;
  for (int i = 0; i < m;) {
    a = 0;
    if (ms[i].first > (ant + 1)) {
      as[a++] = make_pair(1, n);
      ant = ms[i].first - 1;
    } else {
      nex = 1;
      while (i < (m - 1) && ms[i + 1].first == ms[i].first) {
        if (ms[i].second > nex) as[a++] = make_pair(nex, ms[i].second - 1);
        nex = ms[i].second + 1;
        i++;
      }
      if (ms[i].second > nex) as[a++] = make_pair(nex, ms[i].second - 1);
      if (ms[i].second < n) as[a++] = make_pair(ms[i].second + 1, n);
      ant = ms[i].first;
      i++;
    }
    gablah();
  }
  if (ant < n) {
    a = 0;
    as[a++] = make_pair(1, n);
    gablah();
  }
  bool ok = (b > 0 && bs[b - 1].first == n);
  if (ok)
    printf("%d\n", (n - 1) << 1);
  else
    puts("-1");
  return 0;
}
