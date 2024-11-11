#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 8;
struct data {
  int s, f;
  long long c;
};
long long l[N], r[N], nl[N], nr[N];
long long Min[N];
vector<data> day[N];
int trv[N];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  int M = 0;
  for (int i = 1; i <= m; i++) {
    int d;
    data p;
    scanf("%d %d %d %d", &d, &p.s, &p.f, &p.c);
    M = max(M, d);
    day[d].push_back(p);
  }
  long long res = 1e18;
  for (int i = 1; i <= M; i++) {
    for (int ii = 0; ii < day[i].size(); ii++) {
      data p = day[i][ii];
      if (p.s != 0) {
        if (trv[p.s] != 1) {
          trv[p.s] = 1;
          nl[i]++;
          l[i] += p.c;
          Min[p.s] = p.c;
        } else {
          if (Min[p.s] > p.c) {
            l[i] += p.c - Min[p.s];
            Min[p.s] = p.c;
          }
        }
      }
    }
    l[i] += l[i - 1];
    nl[i] += nl[i - 1];
  }
  for (int i = M; i >= 1; i--) {
    for (int ii = 0; ii < day[i].size(); ii++) {
      data p = day[i][ii];
      if (p.s == 0) {
        if (trv[p.f] != 2) {
          trv[p.f] = 2;
          nr[i]++;
          r[i] += p.c;
          Min[p.f] = p.c;
        } else {
          if (Min[p.f] > p.c) {
            r[i] += p.c - Min[p.f];
            Min[p.f] = p.c;
          }
        }
      }
    }
    r[i] += r[i + 1];
    nr[i] += nr[i + 1];
  }
  for (int i = 1; i <= M; i++) {
    if (i + k + 1 > M) break;
    if (nl[i] == nr[i + k + 1] and nl[i] == n) {
      res = min(res, l[i] + r[i + k + 1]);
    }
  }
  if (res < 1e18)
    cout << res;
  else
    cout << -1;
}
