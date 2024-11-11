#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
template <typename T>
T gcd(T a, T b) {
  return (b ? __gcd(a, b) : a);
}
template <typename T>
T lcm(T a, T b) {
  return (a * (b / gcd(a, b)));
}
template <typename T, typename T1>
T amax(T &a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b) {
  if (b < a) a = b;
  return a;
}
template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a) {
  out << "{" << a.first << ", " << a.second << "}";
  return out;
}
const int mod = 1e9 + 7;
template <typename T>
void print(T &a) {
  for (auto &x : a) cout << x << " ";
  cout << "\n";
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool query(long long l, long long r) {
  cout << l << " " << r << endl;
  string s;
  cin >> s;
  if (s == "Yes")
    return 1;
  else if (s == "No")
    return 0;
  else {
    exit(0);
  }
}
void solve() {
  long long n, k;
  cin >> n >> k;
  long long l = 1, r = n;
  while (1) {
    assert(l <= r);
    if ((r - l) <= 4 * k) {
      long long x = l + rng() % (r - l + 1);
      if (query(x, x))
        break;
      else {
        l = max(1ll, l - k);
        r = min(n, r - k);
      }
    }
    long long mid = (l + r) / 2;
    if (query(l, mid)) {
      l = max(1ll, l - k);
      r = min(n, mid + k);
    } else {
      l = max(1ll, mid - k + 1);
      r = min(n, r + k);
    }
  }
}
int main() {
  auto start1 = high_resolution_clock::now();
  int t = 1;
  while (t--) {
    solve();
  }
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop1 - start1);
  return 0;
}
