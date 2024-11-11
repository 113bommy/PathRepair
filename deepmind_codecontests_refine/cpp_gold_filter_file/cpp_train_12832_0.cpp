#include <bits/stdc++.h>
using namespace std;
template <class T>
void _print(T t) {
  cerr << t;
}
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
template <class T, class V>
void _print(vector<pair<T, V>> v) {
  cerr << "[ ";
  for (auto i : v) {
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
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void solve() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    unordered_map<int, int> make_pair;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      make_pair[x]++;
    }
    int maxi = 0;
    for (int i = 1; i <= 2 * n; i++) {
      int total = 0;
      for (auto &j : make_pair) {
        int other = i - j.first;
        if (other >= 1 && make_pair.count(other)) {
          total += min(j.second, make_pair[other]);
        }
      }
      total /= 2;
      maxi = max(maxi, total);
    }
    cout << maxi << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
