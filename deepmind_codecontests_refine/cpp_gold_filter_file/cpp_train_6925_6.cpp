#include <bits/stdc++.h>
using namespace std;
const int MAXM = 200010;
const int MLOG = 19;
int m;
long long d, n;
pair<long long, long long> p[MAXM];
pair<long long, long long> st[MLOG][MAXM];
int val[MAXM];
pair<long long, long long> mp(const pair<long long, long long>& a,
                              const pair<long long, long long>& b) {
  if (a.first != b.first) return a.first < b.first ? a : b;
  return a.second > b.second ? a : b;
}
pair<long long, long long> mval(int a, int b) {
  int x = val[b - a + 1];
  return mp(st[x][a], st[x][b - (1 << x) + 1]);
}
int main(void) {
  scanf("%lld %lld %d", &d, &n, &m);
  val[1] = 0;
  for (int i = 2; i <= m; i++) {
    if ((1 << (val[i - 1] + 1)) <= i)
      val[i] = val[i - 1] + 1;
    else
      val[i] = val[i - 1];
  }
  for (int i = 1; i <= m; i++) {
    scanf("%lld %lld", &p[i].first, &p[i].second);
  }
  m++;
  p[0].first = 0;
  p[0].second = 1e11;
  p[m].first = d;
  p[m].second = 0;
  sort(p, p + m);
  for (int i = 0; i < m; i++) {
    st[0][i].first = p[i].second;
    st[0][i].second = i;
  }
  for (int i = 1; i < MLOG; i++) {
    for (int j = 0; j <= m - (1 << i); j++) {
      st[i][j] = mp(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
    }
  }
  int pos = 0;
  vector<int> v;
  v.push_back(pos);
  while (pos < m) {
    if (p[pos + 1].first - p[pos].first > n) {
      cout << "-1\n";
      return 0;
    }
    if (pos == m - 1) {
      v.push_back(m);
      pos = m;
      continue;
    }
    int j = upper_bound(p + pos + 1, p + m,
                        pair<long long, long long>(p[pos].first + n, 1e11)) -
            p - 1;
    pair<long long, long long> mvp = mval(pos + 1, j);
    long long mv = mvp.first;
    bool done = 0;
    if (mv <= p[pos].second) {
      for (int i = pos + 1; i <= j && !done; i++) {
        if (p[i].second <= p[pos].second) {
          done = 1;
          pos = i;
          v.push_back(pos);
        }
      }
    } else {
      if (d - p[pos].first <= n)
        pos = m;
      else
        pos = (int)mvp.second;
      v.push_back(pos);
    }
  }
  long long tot = 0, gas = n;
  for (int i = 0; i < (int)v.size() - 1; i++) {
    int a = v[i], b = v[i + 1];
    if (p[a].second >= p[b].second) {
      if (gas < p[b].first - p[a].first) {
        tot += p[a].second * (p[b].first - p[a].first - gas);
        gas = 0;
      } else
        gas -= p[b].first - p[a].first;
    } else {
      tot += p[a].second * (n - gas);
      gas = n - (p[b].first - p[a].first);
    }
  }
  cout << tot << "\n";
  return 0;
}
