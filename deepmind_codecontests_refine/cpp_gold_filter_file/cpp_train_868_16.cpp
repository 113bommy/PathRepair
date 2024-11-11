#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
int cnt[15] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int gettime(int month, int day, int hours, int minutes, int seconds) {
  int res = 0;
  for (int i = 0; i < month; ++i) res += cnt[i] * 24 * 60 * 60;
  res += (day - 1) * 24 * 60 * 60;
  res += hours * 60 * 60;
  res += minutes * 60;
  res += seconds;
  return res;
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int month, day, hours, minutes, seconds;
  string tmp;
  vector<int> v;
  vector<pair<int, pair<int, pair<int, pair<int, int> > > > > s;
  int ttt;
  while (scanf("%d-%d-%d %d:%d:%d:", &ttt, &month, &day, &hours, &minutes,
               &seconds) == 6) {
    getline(cin, tmp);
    s.push_back(make_pair(
        month, make_pair(day, make_pair(hours, make_pair(minutes, seconds)))));
    v.push_back(gettime(month, day, hours, minutes, seconds));
  }
  for (int i = 0; i < int((v).size()); ++i) {
    int l = -1;
    int r = i + 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      int curd = v[i] - v[m];
      if (curd >= n)
        l = m;
      else
        r = m;
    }
    if (i - l >= m)
      printf("2012-%02d-%02d %02d:%02d:%02d\n", s[i].first, s[i].second.first,
             s[i].second.second.first, s[i].second.second.second.first,
             s[i].second.second.second.second),
          exit(0);
  }
  printf("-1\n");
  return 0;
}
