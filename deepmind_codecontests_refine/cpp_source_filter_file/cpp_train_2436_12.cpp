#include <bits/stdc++.h>
using namespace std;
const int dr[] = {0, -1, 0, 1, -1, 1, 1, -1};
const int dc[] = {1, 0, -1, 0, 1, 1, -1, -1};
const double eps = 1e-9;
template <class T>
int len(const T &c) {
  return (int)c.size();
}
template <class T>
void cmin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
void cmax(T &a, T b) {
  if (b > a) a = b;
}
template <class T, class U>
T cast(U first) {
  T second;
  ostringstream a;
  a << first;
  istringstream b(a.str());
  b >> second;
  return second;
}
vector<string> split(string s, string first = " ") {
  vector<string> res;
  for (int i(0), _n(len(s)); i < _n; ++i) {
    string a;
    while (i < (int)s.size() && first.find(s[i]) == string::npos) a += s[i++];
    if (!a.empty()) res.push_back((a));
  }
  return res;
}
template <class T>
inline T gcd(T a, T b) {
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  return (b == 0) ? a : gcd(b, a % b);
}
template <class T>
inline T Pow(T b, T p) {
  T ret = 1;
  for (int i(0), _n(p); i < _n; ++i) {
    ret *= b;
  }
  return ret;
}
long long a, b, t1, t2;
string s;
vector<pair<int, int> > v;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> a >> b;
  cin >> s;
  v.push_back(make_pair(a, b));
  for (int i(0), _n(len(s)); i < _n; ++i) {
    if (s[i] == 'U') {
      t2++;
    }
    if (s[i] == 'D') {
      t2--;
    }
    if (s[i] == 'L') {
      t1--;
    }
    if (s[i] == 'R') {
      t1++;
    }
    v.push_back(make_pair(a - t1, b - t2));
  }
  for (int i(0), _n(len(v)); i < _n; ++i) {
    long long hi = 10000000000LL, lo = 0, mid;
    while (hi > lo) {
      mid = (hi + lo) / 2;
      if (mid * t1 == v[i].first && mid * t2 == v[i].second) {
        cout << "YES";
        return 0;
      }
      if (mid * abs(t1) > abs(v[i].first) || mid * abs(t2) > abs(v[i].second)) {
        hi = mid;
        continue;
      }
      lo = mid + 1;
    }
  }
  cout << "NO" << endl;
}
