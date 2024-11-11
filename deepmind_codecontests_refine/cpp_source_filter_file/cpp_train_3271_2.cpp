#include <bits/stdc++.h>
using namespace std;
template <typename t>
t in(t q) {
  cin >> q;
  return q;
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < ((int)(v).size()); ++i) {
    os << v[i];
    if (i != ((int)(v).size()) - 1) os << ",";
  }
  os << "]";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  for (auto it : v) os << "(" << it.first << ":" << it.second << ")";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(" << v.first << "," << v.second << ")";
  return os;
}
const long double PI = acosl(-1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
inline int rand(int l, int r) {
  return uniform_int_distribution<int>(l, r)(rng);
}
inline long long rand(long long l, long long r) {
  return uniform_int_distribution<long long>(l, r)(rng64);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(10);
  int n, m, k;
  cin >> n >> m >> k;
  for (auto i = 0; i < n; i++) {
    for (auto j = 0; j < m; j++) {
      int v;
      cin >> v;
    }
  }
  cout << m * (m - 1) / 2 << '\n';
  if (k) {
    for (auto i = 0; i < m; i++) {
      for (auto j = i + 1; j < m; j++) {
        cout << i + 1 << " " << j + 1 << '\n';
      }
    }
  } else {
    for (auto i = 0; i < m; i++) {
      for (auto j = i + 1; j < m; j++) {
        cout << j + 1 << " " << i + 1 << '\n';
      }
    }
  }
  return 0;
}
