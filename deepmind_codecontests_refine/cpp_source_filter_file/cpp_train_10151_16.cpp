#include <bits/stdc++.h>
using namespace std;
void Print() { cout << endl; }
template <typename T1, typename... T>
void Print(const T1 &t1, const T &...t) {
  cout << t1 << " ";
  Print(t...);
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
const double PI = 3.14159265358979323846;
long long gcd(long long a, long long b) {
  while (b) {
    long long r = a % b;
    a = b, b = r;
  }
  return a;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  long long t, w, b;
  cin >> t >> w >> b;
  long long g = gcd(w, b), f1 = w / g, f2 = b / g, times = t / f1 / f2 / g;
  if (times == 0) {
    long long ans = min(b - 1, w - 1);
    cout << ans / gcd(ans, t) << "/" << t / gcd(ans, t) << endl;
  } else {
    long long ans = times * (1 + min(w - 1, b - 1)), r = t % (f1 * f2 * g);
    ans += min(min(b - 1, w - 1), r);
    cout << ans / gcd(ans, t) << "/" << t / gcd(ans, t) << endl;
  }
  return 0;
}
