#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T maxs(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T mins(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long I = 4e18;
long long mod_inv(long long a, long long m) {
  long long g = m, r = a, first = 0, second = 1;
  while (r != 0) {
    long long q = g / r;
    g %= r;
    swap(g, r);
    first -= q * second;
    swap(first, second);
  }
  return first < 0 ? first + m : first;
}
long long solve() {
  long long first;
  cin >> first;
  vector<array<string, 3>> vec;
  auto add = [&](long long first, string op, long long second) {
    vec.push_back({to_string(first), op, to_string(second)});
  };
  vector<long long> num;
  num.push_back(first);
  add(first, "^", first);
  while (num.back() <= I) {
    add(num.back(), "+", num.back());
    num.push_back(2 * num.back());
  }
  auto create = [&](long long a, long long first) {
    long long p = 0;
    for (long long j = 60; j >= 0; j--) {
      if ((1LL << j) & a) {
        long long val = 1LL << j;
        val *= first;
        add(p, "+", val);
        p += val;
      }
    }
    assert(p == a * first);
  };
  long long val = 1;
  while (2 * val <= first) val *= 2;
  create(val, first);
  long long second = first ^ (first * val);
  add(first, "^", first * val);
  vector<long long> t;
  t.push_back(second);
  while (t.back() <= I) {
    add(t.back(), "+", t.back());
    t.push_back(2 * t.back());
  }
  long long a = mod_inv(first, second);
  long long b = (a * first - 1) / second;
  if (b % 2 == 0) {
    create(a, first);
    create(b, second);
    add(a * first, "^", b * second);
  } else {
    a += second;
    b += first;
    create(a, first);
    create(b, second);
    add(a * first, "^", b * second);
  }
  cout << vec.size() << "\n";
  for (auto i : vec) {
    cout << i[0] << " " << i[1] << " " << i[2] << "\n";
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
