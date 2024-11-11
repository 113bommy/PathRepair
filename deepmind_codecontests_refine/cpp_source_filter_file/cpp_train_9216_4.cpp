#include <bits/stdc++.h>
using namespace std;
const int INF = int(1e9);
const long long INFll = 1ll * INF * INF;
const long double ldINF = 1e+018;
const long double EPS = 0.000000001;
template <typename T>
ostream& operator<<(ostream& out, pair<T, T>& a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T>
istream& operator>>(istream& in, pair<T, T>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T>
istream& operator>>(istream& in, vector<T>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
template <typename T>
ostream& operator<<(ostream& out, vector<T> a) {
  for (int i = 0; i < a.size(); ++i)
    if (i == a.size() - 1)
      out << a[i];
    else
      out << a[i] << " ";
}
int v[4][4];
int n, a, b, c, d;
bool check(int cur) {
  v[0][0] = cur;
  v[0][2] = cur + b - c;
  if (v[0][2] <= 0 || v[0][2] > n) return false;
  v[2][0] = v[0][0] + a - d;
  if (v[2][0] <= 0 || v[2][0] > n) return false;
  v[2][2] = v[0][2] + a - d;
  if (v[2][2] <= 0 || v[2][2] > n) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> a >> b >> c >> d;
  v[0][1] = a;
  v[1][0] = b;
  v[1][2] = c;
  v[2][1] = d;
  long long ans = 0;
  for (int x = 1; x <= n; x++) {
    v[1][1] = x;
    int l = 1, r = n, res1 = n;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid))
        l = mid + 1, res1 = mid;
      else
        r = mid - 1;
    }
    l = 1, r = n;
    int res2 = 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (check(mid))
        r = mid - 1, res2 = mid;
      else
        l = mid + 1;
    }
    if (check(res1) && check(res2)) ans += (res1 - res2 + 1);
  }
  cout << ans << endl;
  return 0;
}
