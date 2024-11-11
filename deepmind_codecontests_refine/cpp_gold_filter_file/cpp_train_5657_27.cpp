#include <bits/stdc++.h>
using namespace std;
template <class T>
int len(const T &c) {
  return (int)c.size();
}
template <class T>
void cmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void cmax(T &a, T b) {
  if (b > a) a = b;
}
vector<pair<long long, long long> > v;
long long n, m, t, t1, t2;
long long cross(pair<long long, long long> o1, pair<long long, long long> o2,
                pair<long long, long long> o3) {
  o2.first -= o1.first;
  o3.first -= o1.first;
  o2.second -= o1.second;
  o3.second -= o1.second;
  return o2.first * o3.second - o2.second * o3.first;
}
int fun(pair<long long, long long> o1) {
  long long lo = 1, hi = n - 1, mid, sig;
  while (hi - lo > 1) {
    mid = (lo + hi) >> 1;
    sig = cross(v[0], v[mid], o1);
    if (sig < 0)
      hi = mid;
    else
      lo = mid;
  }
  if (cross(v[0], v[1], o1) == 0) return 0;
  if (cross(v[0], v[n - 1], o1) == 0) return 0;
  if (cross(v[lo], v[hi], o1) <= 0) return 0;
  return 1;
}
int main() {
  cin >> n;
  for (int i(0), _n(n); i < _n; ++i) {
    cin >> t1 >> t2;
    v.push_back(make_pair(t1, t2));
  }
  reverse(v.begin(), v.end());
  cin >> m;
  int b = 1;
  for (int i(0), _n(m); i < _n; ++i) {
    cin >> t1 >> t2;
    if (!fun(make_pair(t1, t2))) b = 0;
  }
  if (b)
    cout << "YES";
  else
    cout << "NO";
}
