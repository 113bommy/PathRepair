#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int ST = 100010;
const int ST1 = 1000010;
const long long MOD = 1000000007;
long long ABS(long long a) {
  if (a < 0)
    return a * (-1);
  else
    return a;
}
vector<long long> c;
vector<int> l;
int gdc(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
map<int, long long> cc;
vector<pair<int, int> > pp;
int main() {
  int n;
  cin >> n;
  int ans = INF;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    l.push_back(a);
  }
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    c.push_back(a);
  }
  for (int i = 0; i < n; i++) {
    pp.push_back(make_pair(l[i], c[i]));
    int tc = 3;
    if (l[i] == 1)
      tc = 0;
    else if (l[i] % 2 == 0)
      tc = 1;
    else if (l[i] % 2 == 1)
      tc = 2;
    if (cc[l[i]] == 0)
      cc[l[i]] = c[i];
    else
      cc[l[i]] = min(c[i], cc[l[i]]);
  }
  sort(pp.begin(), pp.end());
  reverse(pp.begin(), pp.end());
  map<int, long long>::iterator it = cc.end();
  it--;
  for (;; it--) {
    for (int i = 0; i < n; i++) {
      int p1 = pp[i].first;
      int p2 = pp[i].second;
      int tc = 3;
      if (p1 == 1)
        tc = 0;
      else if (p1 % 2 == 0)
        tc = 1;
      else
        tc = 2;
      int p3 = it->first;
      long long cost = p2 + it->second;
      p1 = gdc(p1, p3);
      if (cc[p1] == 0)
        cc[p1] = cost;
      else
        cc[p1] = min(cost, cc[p1]);
    }
    if (it == cc.begin()) break;
  }
  if (cc[1] == 0)
    cout << -1;
  else
    cout << cc[1];
  return 0;
}
