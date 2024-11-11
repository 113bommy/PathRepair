#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> getLast(set<pair<long long, long long> > &s) {
  auto it = s.end();
  it--;
  return *it;
}
pair<long long, long long> getSecLast(set<pair<long long, long long> > &s) {
  if (s.size() <= 1) assert(0);
  auto it = s.end();
  it--;
  it--;
  return *it;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long test;
  cin >> test;
  while (test--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    set<pair<long long, long long> > s;
    for (long long i = 0; i < a.size(); i++) {
      s.insert({a[i], i});
    }
    long long turn = 0;
    long long last = -1;
    while (s.size() > 0) {
      if (s.size() <= 1) {
        pair<long long, long long> cur = getLast(s);
        if (cur.first != last) {
          s.erase(cur);
          cur.first--;
          if (cur.first != 0) {
            s.insert(cur);
          }
          last = cur.second;
        } else {
          break;
        }
      } else {
        pair<long long, long long> cur = getLast(s);
        if (cur.second != last) {
          s.erase(cur);
          cur.first--;
          if (cur.first != 0) {
            s.insert(cur);
          }
          last = cur.second;
        } else {
          cur = getSecLast(s);
          s.erase(cur);
          cur.first--;
          if (cur.first != 0) {
            s.insert(cur);
          }
          last = cur.second;
        }
      }
      turn++;
    }
    if (turn % 2 == 0) {
      cout << "T" << '\n';
    } else {
      cout << "HL" << '\n';
    }
  }
  return 0;
}
