#include <bits/stdc++.h>
using namespace std;
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  os << "]";
  return os;
}
template <class T>
ostream &operator<<(ostream &os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream &operator<<(ostream &os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
long long arr[100][2];
long long pre[100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long x0, y0, ax, ay, bx, by, xs, ys, t;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
  arr[0][0] = x0;
  arr[0][1] = y0;
  long long c = 1;
  for (long long i = 1; i < 100; i++) {
    long long x1 = arr[i - 1][0] * ax + bx;
    long long y1 = arr[i - 1][1] * ay + by;
    c++;
    arr[i][0] = x1;
    arr[i][1] = y1;
    pre[i] = x1 - arr[i - 1][0] + y1 - arr[i - 1][1];
    if (x1 > 2e16 || y1 > 2e16) break;
  }
  long long ans = 0;
  for (long long i = 0; i < c; i++) {
    long long a = 0;
    long long temp = abs(xs - arr[i][0]) + abs(ys - arr[i][1]);
    long long temp1 = 0;
    long long tim = t;
    tim -= temp;
    if (tim < 0) continue;
    a++;
    ans = max(a, ans);
    for (int j = i; j > 0; j--) {
      temp1 += pre[j];
      tim -= pre[j];
      if (tim < 0) break;
      a++;
      ans = max(a, ans);
    }
    tim -= temp1;
    if (tim < 0) continue;
    for (int j = i + 1; j < c; j++) {
      tim -= pre[j];
      if (tim < 0) break;
      a++;
    }
    ans = max(a, ans);
  }
  cout << ans;
}
