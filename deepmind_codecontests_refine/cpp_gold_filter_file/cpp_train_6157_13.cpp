#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
vector<long long int> ver;
vector<long long int> side;
long long int n;
long long int x1, yy1, x2, y2;
string s;
bool can(long long int mid) {
  long long int x = x1, y = yy1;
  long long int div = mid / n;
  x += div * side[n - 1];
  y += div * ver[n - 1];
  long long int temp = mid;
  mid = mid % n;
  for (__typeof(mid) i = (0) - ((0) > (mid)); i != (mid) - ((0) > (mid));
       i += 1 - 2 * ((0) > (mid))) {
    if (s[i] == 'R') x++;
    if (s[i] == 'L') x--;
    if (s[i] == 'U') y++;
    if (s[i] == 'D') y--;
  }
  long long int want = abs(x - x2) + abs(y - y2);
  return want <= temp;
}
int main() {
  srand(chrono::steady_clock::now().time_since_epoch().count());
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> x1 >> yy1;
  cin >> x2 >> y2;
  cin >> n;
  cin >> s;
  long long int d = abs(x1 - x2) + abs(yy1 - y2);
  if (d == 0) {
    cout << 0;
    exit(0);
  }
  char c1, c2;
  if (x1 > x2 && yy1 > y2) {
    c1 = 'L';
    c2 = 'D';
  }
  if (x1 > x2 && yy1 <= y2) {
    c1 = 'L';
    c2 = 'U';
  }
  if (x1 <= x2 && yy1 > y2) {
    c1 = 'R';
    c2 = 'D';
  }
  if (x1 <= x2 && yy1 <= y2) {
    c1 = 'R';
    c2 = 'U';
  }
  int found = 0;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    if (s[i] == c1 || s[i] == c2) {
      found = 1;
      break;
    }
  }
  if (!found) {
    cout << -1;
    exit(0);
  }
  ver.resize(n, 0);
  side.resize(n, 0);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    if (s[i] == 'R') {
      side[i] = (i == 0) ? 1 : 1 + side[i - 1];
      ver[i] = (i == 0) ? 0 : ver[i - 1];
    }
    if (s[i] == 'L') {
      side[i] = (i == 0) ? -1 : -1 + side[i - 1];
      ver[i] = (i == 0) ? 0 : ver[i - 1];
    }
    if (s[i] == 'U') {
      side[i] = (i == 0) ? 0 : side[i - 1];
      ver[i] = (i == 0) ? 1 : 1 + ver[i - 1];
    }
    if (s[i] == 'D') {
      side[i] = (i == 0) ? 0 : side[i - 1];
      ver[i] = (i == 0) ? -1 : -1 + ver[i - 1];
    }
  }
  long long int l = 0, h = 1e18;
  long long int ans = -1;
  while (l <= h) {
    long long int mid = l + (h - l) / 2;
    if (can(mid)) {
      ans = mid;
      h = mid - 1;
    } else
      l = mid + 1;
  }
  cout << ans;
  return 0;
}
