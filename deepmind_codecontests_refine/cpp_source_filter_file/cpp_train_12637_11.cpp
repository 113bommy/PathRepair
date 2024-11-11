#include <bits/stdc++.h>
using namespace std;
double PI = acos(-1);
double EPS = 1e-7;
long long INF = 1000000000;
long long MAXINT = 2147483647;
long long INFLL = 1000000000000000000LL;
long long MAXLL = 9223372036854775807LL;
pair<long long, long long> M[8] = {
    make_pair(0, 1),  make_pair(1, 0),   make_pair(-1, 0), make_pair(0, -1),
    make_pair(-1, 1), make_pair(-1, -1), make_pair(1, -1), make_pair(1, 1)};
long long d[100005];
long long t[100005];
long long sum[100005];
long long dp[102][100005];
long long n, m, p;
deque<pair<long long, long long> > v;
long long ptr;
bool cek(pair<long long, long long> v1, pair<long long, long long> v2,
         pair<long long, long long> v3) {
  return (v1.second - v2.second) * (v3.first - v1.first) <
         (v1.second - v3.second) * (v2.first - v1.first);
}
void addpoLL(long long M, long long C) {
  while ((long long)v.size() > 2 &&
         cek(v[(long long)v.size() - 2], v[(long long)v.size() - 1],
             make_pair(M, C)))
    v.pop_back();
  v.push_back(make_pair(M, C));
}
long long search(long long s) {
  while ((long long)v.size() > 1 &&
         v[0].first * s + v[0].second < v[1].first * s + v[1].second)
    v.pop_front();
  return v[0].first * s + v[0].second;
}
int main() {
  scanf("%d%d%d", &n, &m, &p);
  d[1] = 0LL;
  for (long long(a) = (2); (a) <= (n); (a)++) {
    scanf("%I64d", &d[a]);
  }
  for (long long(a) = (2); (a) <= (n); (a)++) {
    d[a] += d[a - 1];
  }
  for (long long(a) = (1); (a) <= (m); (a)++) {
    long long h;
    long long tm;
    scanf("%d %I64d", &h, &tm);
    t[a] = tm - d[h];
  }
  sort(t + 1, t + m + 1);
  long long maks = t[m];
  long long sum = 0;
  for (long long(a) = (1); (a) <= (m); (a)++) {
    t[a] = maks - t[a];
    sum += t[a];
  }
  p--;
  for (long long(a) = (1); (a) <= (p); (a)++) {
    v.clear();
    ptr = 0;
    for (long long(b) = (1); (b) <= (m); (b)++) {
      addpoLL(1 - b, dp[a - 1][b - 1]);
      dp[a][b] = (long long)b * t[b] + search(t[b]);
    }
  }
  long long red = 0;
  for (long long(b) = (1); (b) <= (m); (b)++) {
    (red) = max((red), (dp[p][b]));
  }
  cout << sum - red << endl;
}
