#include <bits/stdc++.h>
using namespace std;
template <class T>
constexpr T lcm(T m, T n) {
  return m / __gcd(m, n) * n;
}
template <typename I>
void join(ostream &ost, I s, I t, string d = " ") {
  for (auto i = s; i != t; ++i) {
    if (i != s) ost << d;
    ost << *i;
  }
  ost << endl;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
  for (auto &a : v) is >> a;
  return is;
}
template <typename T, typename U>
bool chmin(T &a, const U &b) {
  return (a > b ? a = b, true : false);
}
template <typename T, typename U>
bool chmax(T &a, const U &b) {
  return (a < b ? a = b, true : false);
}
template <typename T, size_t N, typename U>
void fill_array(T (&a)[N], const U &v) {
  fill((U *)a, (U *)(a + N), v);
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  while (cin >> n) {
    vector<int> a(n);
    cin >> a;
    sort((a).rbegin(), (a).rend());
    vector<bool> check(150001);
    for (auto x : a) {
      if (not check[x + 1])
        check[x + 1] = 1;
      else if (not check[x])
        check[x] = 1;
      else if (x - 1 >= 1 and not check[x - 1])
        check[x - 1] = 1;
    }
    int ans = 0;
    for (long long int i = (1); i <= (150001); ++i) ans += check[i];
    cout << ans << endl;
  }
  return 0;
}
