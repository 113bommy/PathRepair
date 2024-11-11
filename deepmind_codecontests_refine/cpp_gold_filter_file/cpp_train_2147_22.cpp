#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : (-x);
}
template <class T>
T sqr(T x) {
  return x * x;
}
long long K[3], T[3];
long long ct;
bool cmp(pair<long long, long long> p, pair<long long, long long> q) {
  long long t1 = p.second, t2 = q.second;
  long long s1 = t1 - p.first, s2 = t2 - q.first;
  return max(t1 - s1 + ct, max(t1 + ct, t2) - s2 + ct) <
         max(t2 - s2 + ct, max(t2 + ct, t1) - s1 + ct);
}
int main() {
  for (int i = 0; i < 3; ++i) cin >> K[i];
  for (int i = 0; i < 3; ++i) cin >> T[i];
  int n;
  cin >> n;
  vector<pair<long long, long long> > v[4];
  v[0] = vector<pair<long long, long long> >(n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    v[0][i].second = x;
    v[0][i].first = 0;
  }
  for (int i = 0; i < 3; ++i) {
    sort((v[i]).begin(), (v[i]).end(), cmp);
    multiset<long long> s;
    long long tc = -100;
    long long k = K[i];
    ct = T[i];
    for (int j = 0; j < ((int)(v[i]).size());) {
      if (k > 0) {
        --k;
        long long tmp = max(tc, v[i][j].second) + T[i];
        v[i + 1].push_back(pair<long long, long long>(
            v[i][j].first + tmp - v[i][j].second, tmp));
        s.insert(tmp);
        ++j;
      } else {
        tc = max(tc, *s.begin());
        s.erase(s.begin());
        ++k;
      }
    }
  }
  long long res = 0;
  for (int i = 0; i < ((int)(v[3]).size()); ++i) res = max(res, v[3][i].first);
  cout << res << "\n";
  return 0;
}
