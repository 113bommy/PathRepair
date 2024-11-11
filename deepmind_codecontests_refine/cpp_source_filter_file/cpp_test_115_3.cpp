#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
bool canKill(vector<long long> &arr, long long k, long long h) {
  long long cnt = k;
  for (long long i = 1; i < ((long long)(arr).size()); i++) {
    cnt = cnt + min(k, arr[i] - arr[i - 1]);
  }
  return cnt >= h;
}
void solve() {
  long long n, h;
  cin >> n >> h;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort((arr).begin(), (arr).end());
  long long s = 0;
  long long e = 1e10;
  long long ans = e;
  while (s <= e) {
    long long mid = (s + e) / 2;
    if (canKill(arr, mid, h)) {
      ans = mid;
      e = mid - 1;
    } else {
      s = mid + 1;
    }
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  float time = (float)clock() / CLOCKS_PER_SEC;
  cerr << "time taken : " << time << " secs"
       << "\n";
  return 0;
}
