#include <bits/stdc++.h>
using namespace std;
struct line {
  long long m, c;
  double xleft;
  bool type;
  line(long long _m, long long _c) {
    m = _m;
    c = _c;
    type = 0;
  }
  bool operator<(const line &other) const {
    if (other.type) {
      return xleft < other.xleft;
    }
    return m > other.m;
  }
};
double meet(line x, line y) { return 1.0 * (y.c - x.c) / (x.m - y.m); }
struct cht {
  set<line> hull;
  cht() { hull.clear(); }
  bool hasleft(set<line>::iterator node) { return node != hull.begin(); }
  bool hasright(set<line>::iterator node) { return node != prev(hull.end()); }
  void updateborder(set<line>::iterator node) {
    if (hasright(node)) {
      line temp = *next(node);
      hull.erase(temp);
      temp.xleft = meet(*node, temp);
      hull.insert(temp);
    }
    if (hasleft(node)) {
      line temp = *node;
      temp.xleft = meet(*prev(node), temp);
      hull.erase(node);
      hull.insert(temp);
    } else {
      line temp = *node;
      hull.erase(node);
      temp.xleft = -1e18;
      hull.insert(temp);
    }
  }
  bool useless(line left, line middle, line right) {
    return meet(left, middle) > meet(middle, right);
  }
  bool useless(set<line>::iterator node) {
    if (hasleft(node) && hasright(node)) {
      return useless(*prev(node), *node, *next(node));
    }
    return 0;
  }
  void addline(long long m, long long c) {
    line temp = line(m, c);
    auto it = hull.lower_bound(temp);
    if (it != hull.end() && it->m == m) {
      if (it->c > c) {
        hull.erase(it);
      } else {
        return;
      }
    }
    hull.insert(temp);
    it = hull.find(temp);
    if (useless(it)) {
      hull.erase(it);
      return;
    }
    while (hasleft(it) && useless(prev(it))) {
      hull.erase(prev(it));
    }
    while (hasright(it) && useless(next(it))) {
      hull.erase(next(it));
    }
    updateborder(it);
  }
  pair<long long, long long> geez(set<line>::iterator it, long long x) {
    return pair<long long, long long>(it->m * x + it->c, it->m);
  }
  pair<long long, long long> getbest(long long x) {
    line query(0, 0);
    query.xleft = x;
    query.type = 1;
    auto it = hull.lower_bound(query);
    pair<long long, long long> rt = geez(prev(it), x);
    if (it != hull.end()) rt = min(rt, geez(it, x));
    return rt;
  }
  void clear() { hull.clear(); }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  long long bsum = 0;
  long long ssum = 0;
  cht hull;
  hull.addline(0, 0);
  while (m--) {
    long long op;
    cin >> op;
    if (op == 1) {
      long long k;
      cin >> k;
      hull.clear();
      hull.addline(0, -bsum);
      n += k;
    } else if (op == 2) {
      long long k;
      cin >> k;
      hull.addline(n, -bsum - ssum * n);
      n += k;
    } else {
      long long b, s;
      cin >> b >> s;
      bsum += b;
      ssum += s;
    }
    pair<long long, long long> qr = hull.getbest(ssum);
    cout << qr.second + 1 << " " << qr.first + bsum << "\n";
  }
  return 0;
}
