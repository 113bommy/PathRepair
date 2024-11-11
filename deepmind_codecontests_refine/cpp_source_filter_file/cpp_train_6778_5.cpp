#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
template <typename T>
inline istream& operator>>(istream& i, vector<T>& v) {
  for (int j = 0; j < ((int)(v).size()); ++j) i >> v[j];
  return i;
}
template <typename T>
string join(const vector<T>& v) {
  stringstream s;
  for (int i = 0; i < ((int)(v).size()); ++i) s << ' ' << v[i];
  return s.str().substr(1);
}
template <typename T>
inline ostream& operator<<(ostream& o, const vector<T>& v) {
  if ((int)(v).size()) o << join(v);
  return o;
}
template <typename T1, typename T2>
inline istream& operator>>(istream& i, pair<T1, T2>& v) {
  return i >> v.first >> v.second;
}
template <typename T1, typename T2>
inline ostream& operator<<(ostream& o, const pair<T1, T2>& v) {
  return o << v.first << "," << v.second;
}
template <typename T>
inline long long int suma(const vector<T>& a) {
  long long int res(0);
  for (auto&& x : a) res += x;
  return res;
}
const double eps = 1e-10;
const long long int LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MX = 200005;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<long long int> d(m);
  for (int i = 0; i < (m); ++i) {
    int x = (n - i) / m + 1;
    if (!i) x--;
    d[((long long int)i * i) % m] += x;
  }
  long long int ans = 0;
  for (int i = 0; i < (m); ++i) {
    int x = (m - i) % m;
    ans += d[i] * d[x];
  }
  cout << ans << endl;
  return 0;
}
