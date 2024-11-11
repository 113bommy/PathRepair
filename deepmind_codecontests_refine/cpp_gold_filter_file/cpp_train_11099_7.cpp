#include <bits/stdc++.h>
using namespace std;
struct s {
  int d, t, c;
  s() {}
  s(int di, int ti, int ci) {
    d = di;
    t = ti;
    c = ci;
  }
};
struct ans {
  int d;
  long long c;
  ans() {}
  ans(int di, long long ci) {
    d = di;
    c = ci;
  }
};
vector<s> v[2];
vector<ans> a[2];
bool comp(s A, s B) { return A.d < B.d; }
int cost[2][100010];
int main() {
  int n, m, kk;
  scanf("%d %d %d", &n, &m, &kk);
  for (int i = 0; i < m; ++i) {
    int d, f, t, c;
    scanf("%d %d %d %d", &d, &f, &t, &c);
    if (t == 0) {
      v[0].push_back(s(d, f, c));
    } else {
      v[1].push_back(s(d, t, c));
    }
  }
  sort(v[0].begin(), v[0].end(), comp);
  sort(v[1].begin(), v[1].end(), comp);
  reverse(v[1].begin(), v[1].end());
  for (int k = 0; k < 2; ++k) {
    int cnt = 0;
    long long sum = 0, tmp = 0x3FFFFFFFFFFF;
    for (int i = 0; i < int(v[k].size()); ++i) {
      if (!cost[k][v[k][i].t]) {
        cost[k][v[k][i].t] = v[k][i].c;
        sum += v[k][i].c;
        cnt++;
      } else if (cost[k][v[k][i].t] > v[k][i].c) {
        sum += (v[k][i].c - cost[k][v[k][i].t]);
        cost[k][v[k][i].t] = v[k][i].c;
      }
      if (i + 1 == v[k].size() || v[k][i].d != v[k][i + 1].d) {
        if (cnt == n) {
          if (sum < tmp) {
            tmp = sum;
            a[k].push_back(ans(v[k][i].d, sum));
          }
        }
      }
    }
  }
  long long fans = 0x3FFFFFFFFFFF;
  int f = a[1].size() - 1;
  for (int i = 0; i < int(a[0].size()); ++i) {
    while (f != -1 && a[1][f].d - a[0][i].d <= kk) {
      f--;
    }
    if (f != -1 && fans > 0ll + a[0][i].c + a[1][f].c) {
      fans = 0ll + a[0][i].c + a[1][f].c;
    }
  }
  if (fans == 0x3FFFFFFFFFFF) {
    printf("-1\n");
  } else {
    printf("%lld\n", fans);
  }
  return 0;
}
