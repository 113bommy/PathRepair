#include <bits/stdc++.h>
using namespace std;
template <class A, class B>
ostream &operator<<(ostream &out, const pair<A, B> &a) {
  return out << "(" << a.first << "," << a.second << ")";
}
template <class A>
ostream &operator<<(ostream &out, const vector<A> &a) {
  for (const A &it : a) out << it << " ";
  return out;
}
template <class A, class B>
istream &operator>>(istream &in, pair<A, B> &a) {
  return in >> a.first >> a.second;
}
template <class A>
istream &operator>>(istream &in, vector<A> &a) {
  for (A &i : a) in >> i;
  return in;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    vector<long long> v(n);
    cin >> v;
    long long pro = 1, sum = 0, zero = 0;
    for (long long i : v) {
      pro *= i;
      sum += i;
      zero += (i == 0);
    }
    if (sum == 0 && pro == 0) {
      cout << zero << "\n";
    } else if (sum == 0) {
      cout << 1 << "\n";
    } else if (pro == 0) {
      cout << zero + ((zero + sum) == 0 ? 1 : 0) << "\n";
    } else {
      cout << 0 << "\n";
    }
  }
}
