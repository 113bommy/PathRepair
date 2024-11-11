#include <bits/stdc++.h>
const int INF = 1e9;
const long long lINF = 1e18;
const double EPS = 1e-12;
using namespace std;
const int N = 10000;
string s;
long long a[N];
char c[N];
pair<long long, long long> l[N], r[N];
pair<long long, long long> add(long long a, char c,
                               pair<long long, long long> p) {
  if (c == '+') {
    p.first += p.second;
    p.second = a;
  } else {
    p.second *= a;
  }
  return p;
}
int main() {
  cin >> s;
  int cnt = 1;
  for (int i = 0, cur = 0; i < (int)s.length(); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      a[cur] *= 10;
      a[cur] += s[i] - '0';
    } else {
      c[cur] = s[i];
      cur++;
      cnt++;
    }
  }
  l[0] = make_pair(0, 0);
  for (int i = 0; i < cnt; i++) {
    if (i == 0) {
      l[i + 1] = add(a[i], '+', l[0]);
    } else {
      l[i + 1] = add(a[i], c[i - 1], l[i]);
    }
  }
  r[0] = make_pair(0, 0);
  for (int i = cnt - 1, j = 1; i >= 0; i--, j++) {
    if (i == cnt - 1) {
      r[j] = add(a[i], '+', r[0]);
    } else {
      r[j] = add(a[i], c[i], r[j - 1]);
    }
  }
  long long ans = l[cnt - 1].first + l[cnt - 1].second;
  for (int i = 0; i < cnt; i++) {
    pair<long long, long long> p = make_pair(0, a[i]);
    for (int j = i + 1; j < cnt; j++) {
      p = add(a[j], c[j - 1], p);
      long long pp = p.first + p.second;
      pair<long long, long long> p1, p2;
      if (i > 0) {
        p1 = add(pp, c[i - 1], l[i]);
      } else {
        p1 = make_pair(0, pp);
      }
      p2 = make_pair(0, 0);
      if (j < cnt - 1) {
        p2 = r[cnt - 1 - j];
      }
      if (c[j] == '*')
        ans = max(ans, p1.first + p1.second * p2.second + p2.first);
      else
        ans = max(ans, p1.first + p2.first + p1.second + p2.second);
    }
  }
  cout << ans << endl;
  return 0;
}
