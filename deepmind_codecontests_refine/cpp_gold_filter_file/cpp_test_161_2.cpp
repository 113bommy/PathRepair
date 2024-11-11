#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
void _print(long long int t) { cerr << t; }
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
long long int INF = 1e9 + 5;
long long int mod = 998244353;
bool comp(pair<long long int, long long int> &x,
          pair<long long int, long long int> &y) {
  return (x.second - x.first) >= (y.second - y.first);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<pair<long long int, long long int> > a(n);
    for (auto &x : a) {
      cin >> x.first >> x.second;
    }
    vector<bool> vis(n);
    for (long long int i = 0; i < n; i++) {
      if (a[i].first == 1 && a[i].second == n) {
        vis[i] = 1;
      }
    };
    long long int l = 1, r = n;
    for (long long int it = 1; it <= n; it++) {
      if (l == -1) {
        long long int index = -1;
        for (long long int i = 0; i < n; i++) {
          if (vis[i]) {
            continue;
          }
          if (index == -1 ||
              a[i].second - a[i].first > a[index].second - a[index].first) {
            index = i;
          }
        }
        vis[index] = 1;
        l = a[index].first;
        r = a[index].second;
      }
      long long int j = -1;
      for (long long int i = 0; i < n; i++) {
        if (vis[i]) {
          continue;
        }
        if (a[i].first >= l && a[i].second <= r) {
          if (j == -1 || a[i].second - a[i].first > a[j].second - a[j].first) {
            j = i;
          }
        }
      }
      if (j == -1) {
        cout << l << " " << r << " " << l << "\n";
        l = -1;
        continue;
      }
      vis[j] = 1;
      cout << l << " " << r << " ";
      if (r == a[j].second) {
        cout << a[j].first - 1 << "\n";
      } else {
        cout << a[j].second + 1 << "\n";
      }
      l = a[j].first;
      r = a[j].second;
    }
  }
}
