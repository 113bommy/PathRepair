#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &p) {
  in >> p.first >> p.second;
  return in;
}
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &x : v) in >> x;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, const std::pair<T1, T2> &p) {
  out << "[" << p.first << ", " << p.second << "]"
      << "\n";
  return out;
}
long long f(long long bit, vector<long long> &a) {
  if (bit < 0) return 0;
  vector<long long> one, zero;
  for (auto x : a) {
    if (x & (1 << bit))
      one.push_back(x);
    else
      zero.push_back(x);
  }
  if (one.size() == 0 or zero.size() == 0) {
    return f(bit - 1, a);
  }
  return 1LL << bit + min(f(bit - 1, one), f(bit - 1, zero));
}
int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  cin >> a;
  long long ans = f(50, a);
  cout << ans << endl;
}
