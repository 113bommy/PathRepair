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
string s;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(10);
  cin >> s;
  char mn = 'z' + 1;
  for (auto i = 0; i < ((int)(s).size()) - 1; i++) {
    if (s[i] > mn) {
      cout << "Ann" << '\n';
    } else {
      cout << "Mike" << '\n';
    }
    mn = min(mn, s[i]);
  }
  if (s[((int)(s).size()) - 1] > mn) {
    cout << "Ann" << '\n';
  } else {
    cout << "Mike" << '\n';
  }
  return 0;
}
