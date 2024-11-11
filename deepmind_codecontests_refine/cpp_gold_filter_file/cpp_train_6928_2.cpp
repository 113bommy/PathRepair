#include <bits/stdc++.h>
using namespace std;
map<int, int> lhall, rhall;
bool cmp(const pair<int, int> &a, const pair<int, int> &b,
         const pair<int, int> &c) {
  return (long long)(b.first - a.first) * (c.second - b.second) -
             (long long)(b.second - a.second) * (c.first - b.first) >=
         0;
}
bool ask(map<int, int> &hh, const pair<int, int> &pi) {
  map<int, int>::iterator it = hh.lower_bound(pi.first);
  if (it == hh.end()) {
    return false;
  }
  if (it->first == pi.first) {
    return pi.second <= it->second;
  }
  if (it == hh.begin()) {
    return false;
  }
  map<int, int>::iterator j = it--;
  return cmp(*it, pi, *j);
}
void add(map<int, int> &hh, const pair<int, int> &pi) {
  hh[pi.first] = pi.second;
  map<int, int>::iterator it = hh.upper_bound(pi.first);
  if (it != hh.end())
    for (map<int, int>::iterator ii = it++; it != hh.end(); ii = it++) {
      if (!cmp(*it, *ii, pi))
        hh.erase(ii);
      else
        break;
    }
  it = hh.lower_bound(pi.first);
  if (it != hh.begin()) {
    map<int, int>::iterator ii = --it;
    for (; ii != hh.begin();) {
      it = ii--;
      if (cmp(*ii, *it, pi))
        hh.erase(it);
      else
        break;
    }
  }
}
int main() {
  int Q, a, b, c;
  scanf("%d", &Q);
  for (int i = 0; i < Q; i++) {
    scanf("%d%d%d", &a, &b, &c);
    bool fl = ask(lhall, make_pair(b, c)), fr = ask(rhall, make_pair(b, -c));
    if (a == 1) {
      if (!fl) {
        add(lhall, make_pair(b, c));
      }
      if (!fr) {
        add(rhall, make_pair(b, -c));
      }
    } else
      printf("%s\n", fl && fr ? "YES" : "NO");
  }
}
