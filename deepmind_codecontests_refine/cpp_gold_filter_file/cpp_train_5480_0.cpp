#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
const double PI = acos(-1);
const long long INFF = 1e18;
const int INF = 1e9 + 1;
const int mod = 1e9 + 7;
const int MAX = 1e5 + 7;
int n, m;
long long bounty, increase, damage;
long long start_health[MAX], max_health[MAX], regen[MAX];
vector<pair<long long, long long> > st[MAX];
void init() {
  scanf("%d %d", &n, &m);
  scanf("%lld %lld %lld", &bounty, &increase, &damage);
  for (int i = (1); i < (n + 1); ++i)
    scanf("%lld %lld %lld", max_health + i, start_health + i, regen + i);
  for (int i = (1); i < (m + 1); ++i) {
    long long t, p, h;
    scanf("%lld %lld %lld", &t, &p, &h);
    ;
    st[p].push_back(make_pair(t, h));
  }
  return;
}
vector<pair<long long, long long> > seg;
bool die[MAX];
void build() {
  for (int i = (1); i < (n + 1); ++i) {
    st[i].push_back(make_pair(0, start_health[i]));
    sort((st[i]).begin(), (st[i]).end());
    if (increase) {
      if (regen[i] && max_health[i] <= damage) {
        puts("-1");
        exit(0);
      }
      if (!regen[i] && st[i].back().second <= damage) {
        puts("-1");
        exit(0);
      }
    }
    die[i] = 1;
    for (int j = 0; j < (((int)st[i].size())); ++j) {
      long long t = st[i][j].first, h = st[i][j].second;
      if (h > damage) {
        if (!die[i]) seg.push_back(make_pair(t, -1));
      } else {
        if (die[i]) seg.push_back(make_pair(t, 1)), die[i] = 0;
        if (!regen[i] || max_health[i] <= damage) continue;
        long long nt = (damage + regen[i] - h) / regen[i] + t;
        if (j + 1 != ((int)st[i].size()) && nt >= st[i][j + 1].first) continue;
        seg.push_back(make_pair(nt, -1));
        die[i] = 1;
      }
    }
  }
  sort((seg).begin(), (seg).end());
  return;
}
void sol() {
  long long ans = 0, cnt = 0;
  for (auto x : seg) {
    if (x.second == 1) {
      cnt++;
      ans = max(ans, cnt * (bounty + x.first * increase));
    } else {
      ans = max(ans, cnt * (bounty + (x.first - 1) * increase));
      cnt--;
    }
  }
  printf("%lld\n", ans);
  return;
}
int main(void) {
  init();
  build();
  sol();
  return 0;
}
