#include <bits/stdc++.h>
using namespace std;
template <int D, typename T>
struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  Vec(int n = 0, Args... args)
      : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T>
struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}
};
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (y == 0) return 1;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modinv(long long int a, long long int p) {
  return power(a, p - 2, p);
}
Vec<1, long long int> dx(2 * 100010, 0), dy(2 * 100010, 0);
long long int n;
long long int x, y;
bool check(long long int start, long long int finish) {
  long long int get_x, get_y;
  get_x = dx[n] - dx[finish - 1] + dx[start - 1];
  get_y = dy[n] - dy[finish - 1] + dy[start - 1];
  long long int D = abs(x - get_x) + abs(y - abs(get_y));
  if (D > finish - start) {
    return false;
  }
  return true;
}
void solve() {
  cin >> n;
  string s;
  cin >> s;
  cin >> x >> y;
  long long int dist = abs(x) + abs(y);
  if (dist > n or (dist % 2) != (n % 2)) {
    cout << -1 << endl;
    return;
  }
  for (long long int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      dx[i + 1] = dx[i] + 1;
      dy[i + 1] = dy[i];
    } else if (s[i] == 'L') {
      dx[i + 1] = dx[i] - 1;
      dy[i + 1] = dy[i];
    } else if (s[i] == 'U') {
      dx[i + 1] = dx[i];
      dy[i + 1] = dy[i] + 1;
    } else if (s[i] == 'D') {
      dx[i + 1] = dx[i];
      dy[i + 1] = dy[i] - 1;
    }
  }
  if (dx[n] == x and dy[n] == y) {
    cout << 0 << endl;
    return;
  }
  long long int ans = n;
  for (long long int i = 1; i <= n; i += 1) {
    long long int low = i, high = n + 1;
    long long int cur = i;
    if (check(cur, high) == false) {
      continue;
    }
    while (high - low > 1) {
      long long int mid = high + low;
      mid /= 2;
      if (check(cur, mid)) {
        high = mid;
      } else
        low = mid;
    }
    ans = min(ans, high - cur);
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int T = 1;
  for (long long int c = 0; c < T; c++) {
    solve();
  }
  return 0;
}
