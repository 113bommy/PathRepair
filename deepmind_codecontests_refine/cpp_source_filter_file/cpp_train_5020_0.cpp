#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1020202;
int n, m, a[MAXN];
long long pre[MAXN];
pair<long long, long long> ch[MAXN];
pair<long long, long long> operator-(const pair<long long, long long>& p1,
                                     const pair<long long, long long>& p2) {
  return pair<long long, long long>(p1.first - p2.first, p1.second - p2.second);
}
long long cross(const pair<long long, long long>& p1,
                const pair<long long, long long>& p2) {
  return p1.first * p2.second - p1.second * p2.first;
}
int main() {
  scanf("%d", &n);
  ch[m++] = {0, 0};
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    pre[i] = pre[i - 1] + a[i];
    pair<long long, long long> cp = {i, pre[i]};
    if (m >= 2 && cross(cp - ch[m - 2], ch[m - 1] - ch[m - 2]) >= 0) m--;
    ch[m++] = cp;
  }
  for (int i = 1; i < m; ++i) {
    double avg = double(ch[i].second - ch[i - 1].second) /
                 double(ch[i].first - ch[i - 1].first);
    for (long long j = ch[i - 1].first + 1; j <= ch[i].first; ++j)
      printf("%.12f\n", avg);
  }
  return 0;
}
