#include <bits/stdc++.h>
using namespace std;
bool chk[3003][3003];
long long dp2[3003][3003];
pair<long long, long long> dp[3003][3003];
pair<pair<long long, long long>, long long> p1[3003];
long long n, p, s, a[3003], b[3005];
vector<long long> v1, v2;
pair<long long, long long> rec(long long x, long long y) {
  if (chk[x][y]) return dp[x][y];
  if (x == n - 1) {
    if (y == s) {
      dp2[x][y] = 1;
      return make_pair(p1[x].first.first, 1);
    } else if (y == s - 1) {
      dp2[x][y] = 2;
      return make_pair(p1[x].first.second, 0);
    } else {
      dp2[x][y] = 0;
      return make_pair(0, 0);
    }
  }
  chk[x][y] = true;
  if (y == s) {
    pair<long long, long long> p2;
    p2 = rec(x + 1, y);
    if (p2.second == p) {
      dp2[x][y] = 0;
      return dp[x][y] = p2;
    }
    dp2[x][y] = 1;
    p2.first += p1[x].first.first;
    p2.second++;
    return dp[x][y] = p2;
  }
  pair<long long, long long> p2, p3, p4;
  p2 = rec(x + 1, y);
  long long fl = 0;
  if (p2.second != p) {
    fl = 1;
    p2.first += p1[x].first.first;
    p2.second++;
  }
  p3 = rec(x + 1, y + 1);
  p3.first += p1[x].first.second;
  if (p2 > p3) {
    if (fl) dp2[x][y] = 1;
    return dp[x][y] = p2;
  }
  dp2[x][y] = 2;
  return dp[x][y] = p3;
}
int main() {
  scanf("%lld %lld %lld", &n, &p, &s);
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (long long j = 0; j < n; j++) {
    scanf("%lld", &b[j]);
  }
  for (long long i = 0; i < n; i++) {
    p1[i] = make_pair(make_pair(a[i], -b[i]), i);
  }
  sort(p1, p1 + n);
  for (int i = 0; i < n; i++) {
    p1[i].first.second = -p1[i].first.second;
  }
  pair<long long, long long> p2 = rec(0, 0);
  printf("%lld\n", p2.first);
  long long x = 0;
  for (long long i = 0; i < n; i++) {
    if (dp2[i][x] == 2) {
      x++;
      v2.push_back(p1[i].second + 1);
    } else if (dp2[i][x] == 1) {
      v1.push_back(p1[i].second + 1);
    }
  }
  for (long long i = 0; i < v1.size(); i++) {
    printf("%lld ", v1[i]);
  }
  printf("\n");
  for (long long i = 0; i < v2.size(); i++) {
    printf("%lld ", v2[i]);
  }
}
