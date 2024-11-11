#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, const vector<T> &p) {
  os << "[";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const set<T> &p) {
  os << "[";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class T>
ostream &operator<<(ostream &os, const multiset<T> &p) {
  os << "[";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const map<S, T> &p) {
  os << "[";
  for (auto &it : p) os << it << " ";
  return os << "]";
}
template <class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
  return os << "(" << p.first << "," << p.second << ")";
}
template <class S, class T>
ostream &operator<<(ostream &os, const unordered_map<S, T> &v) {
  for (auto i : v) os << '(' << i.first << "=>" << i.second << ')' << ' ';
  return os;
}
template <class T>
bool umin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool umax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const long long N = 2e5 + 10;
const long long mod = 1e9 + 7;
void solve(long long tc) {
  long long n, m;
  cin >> n >> m;
  long long air[m], fac[m], day[m];
  pair<long long, long long> edge[m];
  for (long long i = 0; i < m; i++) {
    cin >> air[i] >> fac[i] >> day[i];
    edge[i] = {air[i], fac[i]};
  }
  long long s = 1, e = 1e9, ans = -1;
  while (s <= e) {
    long long mid = (s + e) / 2;
    vector<long long> vis1(n + 1, 0), vis2(n + 1, 0);
    vector<long long> v1[n + 1], v2[n + 1];
    for (long long i = 0; i < m; i++) {
      if (day[i] <= mid) {
        v1[air[i]].push_back(i);
        v2[fac[i]].push_back(i);
      }
    }
    long long ok = 1;
    for (long long i = 1; i <= n; i++) {
      ok &= (long long)v1[i].size() >= 1;
      ok &= (long long)v2[i].size() >= 1;
      if ((long long)v1[i].size() == 1) {
        long long x = v1[i][0];
        long long airport = edge[x].first;
        long long factory = edge[x].second;
        if (vis1[airport])
          ;
        else if (vis1[airport] || vis2[factory])
          ok = 0;
        else {
          vis1[airport] = 1;
          vis2[factory] = 1;
        }
      }
      if ((long long)v2[i].size() == 1) {
        long long x = v2[i][0];
        long long airport = edge[x].first;
        long long factory = edge[x].second;
        if (vis2[factory])
          ;
        else if (vis1[airport] || vis2[factory])
          ok = 0;
        else {
          vis1[airport] = 1;
          vis2[factory] = 1;
        }
      }
    }
    if (ok) {
      ans = mid;
      e = mid - 1;
    } else
      s = mid + 1;
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  for (long long i = 1; i <= t; i++) solve(i);
  return 0;
}
