#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
long long arr[100002];
int main() {
  long long n, a;
  cin >> n >> a;
  map<long long, long long> m;
  for (long long i = 1; i <= (long long)(1e6); ++i) {
    m[i] = 0;
  }
  m.erase(a);
  long long cnt = 0;
  for (long long i = 0; i < (long long)(n); ++i) {
    long long te;
    cin >> te;
    if (m.find(te) != m.end()) m[te]++;
    if (te != a) continue;
    cnt++;
    vector<long long> v;
    for (auto it : m) {
      if ((it.second) < cnt) v.push_back(it.first);
    }
    for (auto x : v) m.erase(x);
  }
  if (m.size() == 0)
    cout << "-1";
  else
    cout << (m.begin()->first);
}
