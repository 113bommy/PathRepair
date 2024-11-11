#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int IT_MAX = 1 << 17;
const long long MOD = 1000000007;
const int INF = 1034567890;
const long long LL_INF = 1234567890123456789ll;
const double PI = acos(-1);
const long double ERR = 1E-8;
pair<pair<long long, long long>, int> u[300050];
pair<long long, long long> in[300050];
int ch[300050];
vector<long long> V[2];
vector<pair<long long, long long> > F;
long long ans[300050];
int main() {
  long long N, M, T, i, t1, t2, t3, t4, p;
  long long N0 = 0, N1 = 0;
  char c[2];
  scanf("%lld %lld %lld", &N, &M, &T);
  for (i = 0; i < N; i++) {
    scanf("%lld %s", &t1, c);
    t1--;
    if (c[0] == 'R')
      t2 = 1;
    else
      t2 = 0;
    u[i].first = pair<long long, long long>(t1, t2);
    u[i].second = i;
  }
  sort(u, u + N);
  for (i = 0; i < N; i++) {
    ch[u[i].second] = i;
    in[i] = u[i].first;
    in[i].first *= 2;
    if (u[i].first.second == 1) {
      N1++;
      V[1].push_back(2 * u[i].first.first);
    } else {
      N0++;
      V[0].push_back(2 * u[i].first.first);
    }
  }
  t1 = T / M;
  p = t1 * (N1 - N0);
  p %= N;
  p += N;
  p %= N;
  T %= M;
  T *= 2;
  M *= 2;
  t1 = in[p].first, t2 = in[p].second, t3 = 0;
  bool samechk = false;
  while (t3 < T) {
    if (t2 == 1) {
      if (V[0].empty()) {
        t1 = (t1 + T - t3) % M;
        t3 = M;
        break;
      }
      long long cur = (t1 + t3) % M;
      long long st = 0, en = V[0].size() - 1, mi, rv = 0;
      while (st <= en) {
        mi = (st + en) / 2;
        if (V[0][mi] >= cur) {
          rv = mi;
          en = mi - 1;
        } else
          st = mi + 1;
      }
      t4 = V[0][rv];
      if (t4 < cur) t4 += M;
      t4 = (t4 - cur) / 2;
      if (t3 + t4 + 1 >= T) {
        t4 = T - t3;
        t1 = (t1 + t4) % M;
        t3 = M;
        break;
      }
      t1 = (t1 + t4 - 1 + M) % M;
      t3 += t4 + 1;
      t2 = 1 - t2;
    } else {
      if (V[1].empty()) {
        t1 = (t1 - T + t3 + M) % M;
        t3 = M;
        break;
      }
      long long cur = (t1 - t3 + M) % M;
      long long st = 0, en = V[1].size() - 1, mi, rv = V[1].size() - 1;
      while (st <= en) {
        mi = (st + en) / 2;
        if (V[1][mi] <= cur) {
          rv = mi;
          st = mi + 1;
        } else
          en = mi - 1;
      }
      t4 = V[1][rv];
      if (t4 > cur) t4 -= M;
      t4 = (cur - t4) / 2;
      if (t3 + t4 + 1 >= T) {
        t4 = T - t3;
        t1 = (t1 - t4 + M) % M;
        t3 = M;
        break;
      }
      t1 = (t1 - t4 + 1 + M) % M;
      t3 += t4 + 1;
      t2 = 1 - t2;
    }
  }
  for (i = 0; i < N; i++) {
    if (in[i].second == 1)
      F.push_back(
          pair<long long, long long>((in[i].first + T) % M, in[i].second));
    else
      F.push_back(
          pair<long long, long long>((in[i].first - T + M) % M, in[i].second));
  }
  sort(F.begin(), F.end());
  p = -1;
  for (i = 0; i < N; i++) {
    if (t1 == F[i].first) {
      if (t2 != F[i].second || p == -1) p = i;
    }
  }
  if (p == -1) {
    printf("ERR\n");
    while (1)
      ;
  }
  for (i = 0; i < N; i++) ans[i] = F[(ch[i] + p) % N].first;
  for (i = 0; i < N; i++) printf("%lld ", ans[i] / 2 + 1);
  printf("\n");
  return 0;
}
