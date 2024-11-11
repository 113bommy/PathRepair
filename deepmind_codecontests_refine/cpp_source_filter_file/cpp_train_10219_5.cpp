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
ostream& operator<<(ostream& os, const set<T>& second) {
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
ostream& operator<<(ostream& os, const map<T, U>& make_pair) {
  for (auto p : make_pair) os << p.first << " : " << p.second << endl;
  return os;
}
inline long long max(long long a, long long b) { return a > b ? a : b; }
inline long long min(long long a, long long b) { return a < b ? a : b; }
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}
map<long long, long long> id;
map<long long, long long> id1;
long long frq[100009];
int32_t main() {
  boost();
  long long t = 1;
  while (t--) {
    long long n, k, res = 0;
    cin >> n >> k;
    long long a[k];
    for (long long i = 0; i < k; i++) {
      cin >> a[i];
      if (frq[a[i] - 1] == 0) id1[a[i] - 1] = i;
      frq[a[i] - 1]++;
      id[a[i] - 1] = i;
    }
    for (long long i = 0; i < n; i++) {
      if (frq[i] == 0) res++;
      if (i < n - 1 && frq[i] == 1 && frq[i + 1] == 0) res++;
      if (i > 0 && frq[i] == 1 && frq[i - 1] == 0) res++;
      if (i < n - 1 && frq[i] == 0 && frq[i + 1] == 1) res++;
      if (i > 0 && frq[i] == 0 && frq[i - 1] == 1) res++;
      if (i < n - 1 && frq[i] == 0 && frq[i + 1] == 0) res++;
      if (i > 0 && frq[i] == 0 && frq[i - 1] == 0) res++;
      if (i < n - 1 && frq[i] >= 1 && frq[i + 1] >= 1 && id[i] > id[i + 1] &&
          id1[i] > id[i + 1])
        res++;
      if (i > 0 && frq[i] >= 1 && frq[i - 1] >= 1 && id[i] > id[i - 1] &&
          id1[i] > id[i - 1])
        res++;
    }
    cout << res << endl;
  }
  return 0;
}
