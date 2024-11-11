#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
template <typename T>
using Array = vector<T>;
template <typename T>
using Matrix = Array<Array<T>>;
using Graph = Matrix<int>;
template <typename T>
bool relax(T& r, const T& first) {
  if (first < r) {
    r = first;
    return true;
  }
  return false;
}
template <typename T>
bool heavy(T& h, const T& first) {
  if (h < first) {
    h = first;
    return true;
  }
  return false;
}
const int DX[8] = {-1, +1, +0, +0, +1, -1, +1, -1};
const int DY[8] = {+0, +0, -1, +1, +1, -1, -1, +1};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, s;
  cin >> n >> s;
  int ans = s / n;
  s %= n;
  if (s) ans++;
  cout << ans;
  return false;
}
