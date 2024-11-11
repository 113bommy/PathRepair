#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
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
void precision(int a) { cout << setprecision(a) << fixed; }
pair<int, int> cntDist(vector<int> &v) {
  pair<int, int> ans;
  for (int i = 0; i < 26; i++) {
    if (v[i] > 0) {
      ans.first++;
      ans.second = max(ans.second, v[i]);
    }
  }
  return ans;
}
void solve() {
  int t;
  cin >> t;
  while (t--) {
    char c;
    int n;
    cin >> n >> c;
    string s;
    cin >> s;
    int seen = 0;
    for (int i = 1; i < n; i++) {
      if (s[i] != s[i - 1]) {
        seen = 1;
        break;
      }
    }
    if (seen == 0) {
      cout << 0 << endl;
      continue;
    }
    int idx = 0;
    for (int i = n / 2 + 1; i <= n; i++) {
      if (s[i - 1] == c) {
        idx = i;
        break;
      }
    }
    if (idx) {
      cout << 1 << endl << idx << endl;
    } else {
      cout << 2 << endl << n - 1 << " " << n << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  return 0;
}
