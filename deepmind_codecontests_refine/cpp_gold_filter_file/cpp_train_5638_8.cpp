#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (auto u : v) {
    os << u;
    if (u != *v.rbegin()) os << ",";
  }
  os << "]" << endl;
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const multiset<T>& second) {
  os << "{";
  for (auto u : second) {
    os << u;
    if (u != *second.rbegin()) os << ",";
  }
  os << "}" << endl;
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
  os << "{";
  os << p.first << "," << p.second;
  os << "}" << endl;
  return os;
}
template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& mp) {
  for (auto p : mp) os << p.first << " : " << p.second << endl;
  return os;
}
inline long long max(long long a, long long b) { return a > b ? a : b; }
inline long long min(long long a, long long b) { return a < b ? a : b; }
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
vector<pair<long long, long long>> mm;
bool cmp(pair<long long, long long>& a, pair<long long, long long>& b) {
  return mm[a.second - 1].second > mm[b.second - 1].second;
}
bool cmp1(pair<long long, long long>& a, pair<long long, long long>& b) {
  return mm[a.second - 1].second < mm[b.second - 1].second;
}
int32_t main() {
  boost();
  long long t = 1;
  while (t--) {
    long long n, a, b;
    vector<pair<long long, long long>> vp, vp1;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cin >> a >> b;
      mm.push_back({a, b});
      if (a < b)
        vp.push_back({b, i + 1});
      else {
        vp1.push_back({b, i + 1});
      }
    }
    sort(vp.begin(), vp.end(), cmp);
    sort(vp1.begin(), vp1.end(), cmp1);
    if (vp.size() >= vp1.size()) {
      cout << vp.size() << endl;
      for (auto ii : vp) {
        cout << ii.second << " ";
      }
    } else {
      cout << vp1.size() << endl;
      for (auto ii : vp1) {
        cout << ii.second << " ";
      }
    }
  }
  return 0;
}
