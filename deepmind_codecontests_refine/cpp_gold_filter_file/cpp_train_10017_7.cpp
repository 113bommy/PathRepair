#include <bits/stdc++.h>
using namespace std;
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
void err(istream_iterator<string> it) { cout << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ' ';
  err(++it, args...);
}
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  for (auto it : v) os << it.first << " : " << it.second << "\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
long long powr(long long a, long long b) {
  a %= 1000000007LL;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % 1000000007LL;
    a = a * a % 1000000007LL;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, a, even(0), odd(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a % 2)
      odd++;
    else
      even++;
  }
  if (odd == n && odd % 2)
    cout << n;
  else if (odd == n && odd % 2 == 0)
    cout << 0;
  else if (odd % 2 == 1)
    return cout << odd, 0;
  else
    cout << even;
}
