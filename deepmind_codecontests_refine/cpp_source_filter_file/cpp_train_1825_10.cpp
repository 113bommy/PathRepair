#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
vector<pair<char, long long>> parse(int n) {
  vector<pair<char, long long>> s(n);
  for (int i = 0; i < n; ++i) {
    long long x;
    char c;
    scanf("%lld-%c", &x, &c);
    s[i].first = c;
    s[i].second = x;
  }
  vector<pair<char, long long>> res;
  int p = 0;
  while (p < n) {
    int q = p;
    long long cnt = 0;
    while (q < n && s[q].first == s[p].first) {
      cnt += s[q].second;
      ++q;
    }
    res.push_back(make_pair(s[p].first, cnt));
    p = q;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(12);
  cout << fixed;
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<char, long long>> s = parse(n);
  vector<pair<char, long long>> t = parse(m);
  n = s.size();
  m = t.size();
  long long res = 0;
  if (m == 1) {
    for (int i = 0; i < n; ++i) {
      if (s[i].first == t[0].first)
        res += max(0LL, s[i].second - t[0].second + 1);
    }
  } else if (m == 2) {
    for (int i = 0; i + 1 < n; ++i) {
      if (s[i].first == t[0].first && s[i + 1].first == t[1].first &&
          s[i].second >= t[0].second && s[i + 1].second >= t[1].second)
        res += 1;
    }
  } else {
    vector<pair<char, long long>> w(t.begin() + 1, t.begin() + m - 1);
    w.push_back(make_pair('-', 1));
    w.insert(w.end(), s.begin(), s.end());
    int nz = m - 2 + 1 + n;
    vector<int> z(nz, 0);
    for (int i = 1, l = 0, r = 0; i < nz; ++i) {
      if (i <= r) z[i] = min(r - i + 1, z[i - l]);
      while (i + z[i] < nz && w[z[i]] == w[i + z[i]]) ++z[i];
      if (i + z[i] - l > r) l = i, r = i + z[i] - l;
    }
    for (int i = 1; i + m - 2 < n; ++i) {
      if (z[m - 1 + i] == m - 2) {
        if (s[i - 1].first == t[0].first &&
            s[i + m - 2].first == t[m - 1].first &&
            s[i - 1].second >= t[0].second &&
            s[i + m - 2].second >= t[m - 1].second)
          res += 1;
      }
    }
  }
  printf("lld\n", res);
  return 0;
}
