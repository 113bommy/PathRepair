#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnf(2106);
const int N = 100005;
int n, w;
int x[N], v[N];
bool so(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.first * 1LL * b.second) < (b.first * 1LL * a.second);
}
bool hav(const pair<int, int>& a, const pair<int, int>& b) {
  return (a.first * 1LL * b.second) == (b.first * 1LL * a.second);
}
pair<int, int> a[N];
bool so1(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first < b.first) return true;
  if (a.first > b.first) return false;
  bool z1 = (a.first < a.second);
  bool z2 = (b.first < b.second);
  if (z1 > z2) return true;
  if (z1 < z2) return false;
  if (z1) {
    return a.second > b.second;
  } else {
    return a.second > b.second;
  }
}
int t[N * 8];
void ubd(int tl, int tr, int x, int pos) {
  if (tl == tr) {
    t[pos]++;
    return;
  }
  int m = (tl + tr) / 2;
  if (x <= m)
    ubd(tl, m, x, pos * 2);
  else
    ubd(m + 1, tr, x, pos * 2 + 1);
  t[pos] = t[pos * 2] + t[pos * 2 + 1];
}
int qry(int tl, int tr, int l, int r, int pos) {
  if (l > r) return 0;
  if (tl == l && tr == r) return t[pos];
  int m = (tl + tr) / 2;
  return (qry(tl, m, l, min(m, r), pos * 2) +
          qry(m + 1, tr, max(m + 1, l), r, pos * 2 + 1));
}
void solv() {
  scanf("%d%d", &n, &w);
  vector<pair<int, int> > b;
  if (w == 0) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d", &x[i], &v[i]);
      b.push_back(make_pair(abs(x[i]), abs(v[i])));
    }
    sort((b).begin(), (b).end(), so);
    int q = 0;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      if (!i || !hav(b[i], b[i - 1])) {
        ans += (q * 1LL * (q - 1)) / 2;
        q = 1;
      } else
        ++q;
    }
    ans += (q * 1LL * (q - 1)) / 2;
    printf("%lld\n", ans);
    return;
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &x[i], &v[i]);
    v[i] += w;
    b.push_back(make_pair(abs(x[i]), abs(v[i])));
    v[i] -= w;
    v[i] -= w;
    b.push_back(make_pair(abs(x[i]), abs(v[i])));
    v[i] += w;
  }
  sort((b).begin(), (b).end(), so);
  int z = 0;
  map<pair<int, int>, int> mp;
  for (int i = 0; i < b.size(); ++i) {
    if (!i || !hav(b[i], b[i - 1]))
      mp[b[i]] = ++z;
    else
      mp[b[i]] = z;
  }
  for (int i = 1; i <= n; ++i) {
    v[i] += w;
    a[i].first = mp[(make_pair(abs(x[i]), abs(v[i])))];
    v[i] -= w;
    v[i] -= w;
    a[i].second = mp[(make_pair(abs(x[i]), abs(v[i])))];
    v[i] += w;
  }
  sort(a + 1, a + n + 1, so1);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i].first < a[i].second) {
      ubd(1, z, a[i].second, 1);
    } else {
      ans += qry(1, z, a[i].second, z, 1);
    }
  }
  memset(t, 0, sizeof t);
  for (int i = 1; i <= n; ++i) {
    if (a[i].first < a[i].second) {
      ans += qry(1, z, a[i].second, z, 1);
      ubd(1, z, a[i].second, 1);
    }
  }
  memset(t, 0, sizeof t);
  for (int i = 1; i <= n; ++i) {
    if (a[i].first > a[i].second) {
      ans += qry(1, z, a[i].second, z, 1);
      ubd(1, z, a[i].second, 1);
    }
  }
  printf("%lld\n", ans);
}
int main() {
  solv();
  return 0;
}
