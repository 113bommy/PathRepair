#include <bits/stdc++.h>
using namespace std;
long long R = pow(10, 9) + 7;
template <typename T>
T last(vector<T>& v) {
  return v[v.size() - 1];
}
template <typename T>
void prll(vector<T>& v) {
  for (long long i = 0; i < v.size(); i++) {
    cout << v[i] << ' ';
  }
  cout << endl;
}
template <typename T1, typename T2>
void prll(vector<pair<T1, T2>>& v) {
  cout << "[";
  for (long long i = 0; i < v.size(); i++) {
    cout << '(' << v[i].first << ',' << v[i].second << "),";
  }
  cout << "]" << endl;
}
template <typename T>
void prll(vector<vector<T>>& v) {
  cout << "[";
  for (long long i = 0; i < v.size(); i++) {
    prll(v[i]);
  }
  cout << "]" << endl;
}
template <typename T>
void prll(set<T>& v) {
  cout << "{";
  for (auto i : v) {
    cout << i << ' ';
  }
  cout << "}" << endl;
}
template <typename T1, typename T2>
void prll(map<T1, T2>& v) {
  cout << "{";
  for (auto i : v) {
    cout << i.first << ':' << i.second << ',';
  }
  cout << "}" << endl;
}
template <typename T>
bool in(set<T>& indices, T x) {
  return indices.find(x) != indices.end();
}
template <typename T, typename T_>
bool in(map<T, T_>& indices, T x) {
  return indices.find(x) != indices.end();
}
long long power(long long x, long long y) {
  long long res = 1;
  x = x % R;
  if (x == 0) return 0;
  while (y > 0) {
    if (y % 2 == 1) res = (res * x) % R;
    y /= 2;
    x = (x * x) % R;
  }
  return res;
}
void TestCase() {
  long long n;
  cin >> n;
  vector<pair<long long, long long>> v(n);
  for (long long i = 0; i < n; i++) cin >> v[i].first;
  for (long long i = 0; i < n; i++) cin >> v[i].second;
  sort(v.begin(), v.end());
  long long i = 0;
  long long curr = 0;
  multiset<pair<long long, long long>> s;
  long long cost = 0;
  while (i < n || !s.empty()) {
    if (s.empty()) {
      curr = v[i].first;
    } else {
      curr++;
    }
    while (i < n && v[i].first == curr) {
      s.insert({-v[i].second, v[i].first});
      i++;
    }
    cost += (curr - s.begin()->second) * (-s.begin()->first);
    s.erase(s.begin());
  }
  cout << cost << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T;
  T = 1;
  for (long long tt = 1; tt <= T; tt++) {
    TestCase();
  }
}
